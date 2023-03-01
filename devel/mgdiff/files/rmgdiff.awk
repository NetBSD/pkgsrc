#
# rmgdiff.awk
#             -- awk script to that reads standard input for the output
#                of "diff -rq <dir1> <dir2>".  It then takes diff's
#                output and calls mgdiff once for each pair of text
#                files that differ.  It prints out a message to this
#                effect.  It then prints out a list of binary files
#                that have differences followed by a list of files
#                that appear only in the first directory followed by a
#                list of files that appear only in the second
#                directory.
#
#                It expects you to pass in <dir1> and <dir2> on the
#                command line using awk's "-v" option.  You should
#                find the shell script I use to call this file near
#                where you found this file.
#
#                                            -- Paul Serice
#

#
# Changes:
#
#  v1.8.1   Minor clean up.
#
#  v1.8.0   Testing revealed problems handling white space.
#
#  v1.7     Fixed a problem with the regular expression that
#           escapes meta-characters in the escape_dir() function.
#           Now, both gawk and mawk should be able to interpret this
#           script.
#
#  v1.6     Changed the "rmgdiff" shell script wrapper so that this
#           awk script does not have to be in the same directory.
#           You can now place both "rmgdiff" and "rmgdiff.awk" in
#           any directory and place a symbolic link in a "bin"
#           directory that points to the "rmgdiff" shell script.
#           The shell script will then follow the symbolic links
#           in order to find the "rmgdiff.awk" script.  One way to
#           set this up is as follows:
#
#                 /usr/local/lib/rmgdiff/rmgdiff
#                 /usr/local/lib/rmgdiff/rmgdiff.awk
#                 /usr/local/bin/rmgdiff -> ../lib/rmgdiff/rmgdiff
#
#  v1.5     I've said it before, and here I go again.  This time
#           it's fixed.  v1.4 introduced a new bug related to the same
#           section of code that v1.3 and v1.4 was trying to fix.
#           This new bug manifested itself when a subdirectory was
#           only in one directory and had a minimum depth of at least
#           2.  Everything that was originally a bug and everything I
#           subsequently broke now appears to work.
#  v1.4     Was finally able to reproduce the bug that was causing
#           reported directories to appear to have been split
#           incorrectly.  Problem solved.
#  v1.3     Forgot to escape the accidental meta-characters in the
#           directory names.  Also, I am explicitly putting both the
#           "rmgdiff" shell script and this "rmgdiff.awk" awk script
#           in the public domain.  (It has always been in the public
#           domain.  This just makes it official.  Use at your own
#           risk.)
#  v1.2     Changed the way the "rmgdiff" shell script initialized the
#           RMGDIFF_GUI variable.
#  v1.1     Fixed bug in "/^Binary file /" rule that used "$4" and "$6"
#           instead of "$3" and "$5".
#  v1.0     Initial release
# 

#
# trim_dir(dir) -- A user can enter a directory such as "dir", "dir/", 
#                  "dir//", etc.  trim_dirr() will reduce all of these
#                  to "dir" by removing all trailing slashes.
#
function trim_dir( dir  ,  pos ) {
  if( !dir )
    return "";

  pos = length(dir);
  while( pos > 0 )
    {
      if( substr(dir, pos, 1) != "/" )
        break;
      pos--;
    }

  # If you made it back to the beginning, then "dir" was all slashes
  # which is a synonym for the root dir.
  if( pos <= 0 )
    return "/";
  else
    return substr(dir, 1, pos);
}


#
# escape_dir(dir) -- Escape the characters in the directory name that
#                    are coincidentally meta characters.
#
function escape_dir(dir) {
    gsub(/[[\]{}()^$. +|*?]/, "\\\\&", dir);
    return dir;
}


#
# relative_path(full_path, upper_dir)
#
#         This function strips off the upper most directory.  This
#         lets you report a difference just by reporting the relative
#         path.  Thus, "dir1/abcd/efgh" and "dir2/abcd/efgh" can be
#         reported as being different by referring to "a difference in
#         the abcd/efgh files that reside in both directories."
#
function relative_path( full_path, upper_dir  ,  pos ) {
  if( index(full_path, upper_dir) != 1 )
    {
      print("***");
      print("*** rmgdiff.awk: Internal error. ");
      print("***              " upper_dir );
      print("***              can't possibly be the base directory of ");
      print("***              " full_path ".");
      print("***");
      exit_flag = 1;
      exit(1);
    }

  pos = length(upper_dir) + 1;
  full_path_len = length(full_path);

  while( pos <= full_path_len )
    {
      if( substr(full_path, pos, 1) != "/")
        break;
      pos++;
    }
  
  # If "pos" makes it all the way to the end of "full_path", then the
  # user passed in the name of a single directory instead of a path.
  if( pos == length )
    return "";
  else
    return substr(full_path, pos);
}


#
# get_file_type() -- Returns the relevant part of the description returned
#                    by "file".  Unlike for Linux, the "file" command for
#                    SGI will have in indeterminate number of spaces before
#                    the relevant partion.  Hence the iterative solution.
#                    Perhaps it would be better to use 'FS= ' (?).
#
function get_file_type( file_name, \
                        cmd, pos, file_type, file_type_len, next_ch) {
  cmd = file_cmd " \"" file_name "\"";
  if( (cmd | getline file_type) == -1)
    {
      print("");
      print("rmgdiff.awk:  Unable to determine file type of " $2 ".");
      print("              This usually occurs because you don't have any " \
                           "available");
      print("              file descriptors or \"file\" is not in your path.");
      print("");
      exit_flag = 1;
      exit(1);
    }
  close(cmd);

  # Start right after the colon that always follows the file name.
  pos = length(file_name) + 2;
  file_type_len = length(file_type);

  # Iterate until you find the first non-space and non-tab.  I did it
  # like this because different versions of Unix have different spacing.
  while( pos <= file_type_len )
    {
      next_ch = substr(file_type, pos, 1);
      if( (next_ch != " ") && (next_ch != "\t") )
        break;
      pos++;
    }
  
  if( pos > file_type_len )
    {
      print("***");
      print("*** rmgdiff.awk: Internal error.  Missed a file type for");
      print("***              "  file_name);
      print("***");
      exit_flag = 1;
      exit(1);
    }
  
  return substr(file_type, pos);
}


#
# add_only_in(dir, str3, str4) -- routine to convert $3 and $4 of the
#                                 output of diff when the file is only
#                                 in one directory into something we can
#                                 later print.
#
function add_only_in(dir, str3, str4  ,  middle, fullpath, file_type) {

  middle = relative_path(str3, dir);
  
  if( middle == "" )
    fullpath = dir "/" str4;
  else
    fullpath = dir "/" middle "/" str4;
  
  file_type = get_file_type(fullpath);
  
  if( debug )
    print("file_type = " file_type);
  
  if( dir == dir1 )
    {
      if( debug )
        print("Adding " fullpath " to only_in_dir1[" only_in_dir1_cnt "].");

      if( show_file_types )
        only_in_dir1[only_in_dir1_cnt++] = fullpath "  (" file_type ")";
      else
        only_in_dir1[only_in_dir1_cnt++] = fullpath;
    }
  else if( dir == dir2 )
    {
      if( debug )
        print("Adding " fullpath " to only_in_dir2[" only_in_dir2_cnt "].");

      if( show_file_types )
        only_in_dir2[only_in_dir2_cnt++] = fullpath "  (" file_type ")";
      else
        only_in_dir2[only_in_dir2_cnt++] = fullpath;
    }
  else
    {
      print("***");
      print("*** rmgdiff.awk: Internal error.  Can't figure out " \
            "\"only in\" directory.");
      print("***");
      exit_flag = 1;
      exit(1);
    }
}



#
# add_binary(full_name_1, full_name_2)
#          -- Determines what type of binary a file is and adds it
#             to the appropriate list for reporting later.  Make
#             sure "full_name_1" is the full_name associated with
#             "dir1" (which is a global variable).
#

function add_binary(full_name_1, full_name_2  ,  file_type_1, file_type_2) {
  file_type_1 = get_file_type(full_name_1);
  file_type_2 = get_file_type(full_name_2);
  
  if( debug )
    {
      print("full_name_1 = " full_name_1);
      print("full_name_2 = " full_name_2);
      print("file_type_1 = " file_type_1);
      print("file_type_2 = " file_type_2);
    }

  if( file_type_1 ~ /executable/ && file_type_2 ~ /executable/ )
    {
      if( debug )
        print("Adding " relative_path(full_name_1, dir1) \
              " to executable_files[" executable_files_cnt "].");

      if( show_file_types )
        executable_files[executable_files_cnt++] \
          = relative_path(full_name_1, dir1) "  (" file_type_1 ")";
      else
        executable_files[executable_files_cnt++] \
          = relative_path(full_name_1, dir1);
    }
  else if( file_type_1 ~ /shared object/ && file_type_2 ~ /shared object/ )
    {
      if( debug )
        print("Adding " relative_path(full_name_1, dir1) " to shared_libs[" \
              shared_libs_cnt "].");

      if( show_file_types )
        shared_libs[shared_libs_cnt++] \
          = relative_path(full_name_1, dir1) "  (" file_type_1 ")";
      else
        shared_libs[shared_libs_cnt++] \
          = relative_path(full_name_1, dir1);
    }
  else if( file_type_1 ~ /ar archive/ && file_type_2 ~ /ar archive/ )
    {
      if( debug )
        print("Adding " relative_path(full_name_1, dir1) " to static_libs[" \
              static_libs_cnt "].");

      if( show_file_types )
        static_libs[static_libs_cnt++] \
          = relative_path(full_name_1, dir1) "  (" file_type_1 ")";
      else
        static_libs[static_libs_cnt++] \
          = relative_path(full_name_1, dir1);
    }
  else if( file_type_1 ~ /relocatable/ && file_type_2 ~ /relocatable/ )
    {
      if( debug )
        print("Adding " relative_path(full_name_1, dir1) " to object_files[" \
              object_files_cnt "].");

      if( show_file_types )
        object_files[object_files_cnt++] \
          = relative_path(full_name_1, dir1) "  (" file_type_1 ")";
      else
        object_files[object_files_cnt++] \
          = relative_path(full_name_1, dir1);
    }
  # gzip files report a date which is causing them to appear
  # to be mismatched.  Avoid a mismatch with this rule.
  else if ( file_type_1 ~ /gzip compressed data/ &&
            file_type_2 ~ /gzip compressed data/ )
    {
      if( debug )
        {
	  print("Matched a gzipped file.  I'll be making up a type!!!");
          print("Adding " relative_path(full_name_1, dir1) \
                " to other_bin_files[" other_bin_files_cnt "].");
        }

      if( show_file_types )
        other_bin_files[other_bin_files_cnt++] \
          = relative_path(full_name_1, dir1) "  (gzip compressed data)";
      else
        other_bin_files[other_bin_files_cnt++] \
          = relative_path(full_name_1, dir1);
    }
  # Mismatched types.
  else if ( file_type_1 !~ file_type_2 )  
    {
      if( debug )
        {
          print("Adding " relative_path(full_name_1, dir1) \
                " to mismatched_files[" mismatched_files_cnt "].");
          print("File types differ!");
        }
      
      mismatched_files[mismatched_files_cnt++] \
        = relative_path(full_name_1, dir1) \
          "  (Types differ.  See next two lines.)\n" \
          "       " dir1 ":  (" file_type_1 ")\n" \
          "       " dir2 ":  (" file_type_2 ")";
    }
  else
    {
      if( debug )
        print("Adding " relative_path(full_name_1, dir1) \
              " to other_bin_files[" other_bin_files_cnt "].");

      if( show_file_types )
        other_bin_files[other_bin_files_cnt++] \
          = relative_path(full_name_1, dir1) "  (" file_type_1 ")";
      else
        other_bin_files[other_bin_files_cnt++] \
          = relative_path(full_name_1, dir1);
    }
}


#
# add_text(full_name_1, full_name_2, file_type_1, file_type2)
#          -- We don't really need to "add" an entry to note that
#             we have found a text file.  Instead, we go ahead and
#             print out the file's name and start up the GUI.
#
function add_text(full_name_1, full_name_2, file_type_1, file_type_2) {
  if( debug )
    {
      print("full_name_1 = " full_name_1);
      print("full_name_2 = " full_name_2);
      print("file_type_1 = " file_type_1);
      print("file_type_2 = " file_type_2);
    }
  
  if( first_diff )
    {
      printf("\n*** DIFFERENT TEXT FILES ***\n\n");
      first_diff = 0;
    }
  
  if( file_type_1 == file_type_2 )
    if( show_file_types )
      print(relative_path(full_name_1, dir1) "  (" file_type_1 ")");
    else
      print(relative_path(full_name_1, dir1));
  else
    {
      print("=====");
      print(relative_path(full_name_1, dir1) "  (Types differ.  " \
            "See next two lines)");
      print("       " dir1 ":  (" file_type_1 ")");
      print("       " dir2 ":  (" file_type_2 ")");
      print("=====");
    }
  
  if(use_gui)
    system(rmgdiff_gui " \"" full_name_1 "\" \"" full_name_2 "\"");
}


#
# add_text_or_binary(full_name_1, full_name_2)
#              -- Used to detect whether we have text files that differ
#                 or something else.  It sure would be nice if we could
#                 pass these strings by reference.
#
function add_text_or_binary(full_name_1, full_name_2 , file_type_1, file_type_2)
{
  file_type_1 = get_file_type(full_name_1);
  file_type_2 = get_file_type(full_name_2);
  
  if( (file_type_1 ~ /text/ || file_type_1 ~ /^empty$/) &&
      (file_type_2 ~ /text/ || file_type_2 ~ /^empty$/) )
    {
      add_text(full_name_1, full_name_2, file_type_1, file_type_2);
    }
  else
    {
      add_binary(full_name_1, full_name_2);
    }
}



function check_exec(exec  ,  cmd) {
  cmd="type \"" exec "\" 1>/dev/null 2>&1";
  if( system(cmd) != 0 )
    {
      printf("\nrmgdiff.awk: " exec " isn't executable.\n\n");
      exit_flag = 1;
      exit(1);
    }
}


function check_dir(dir  ,  cmd) {
  cmd = "[ -d \"" dir "\" ]";
  if( system(cmd) != 0 )
    {
      printf("\nrmgdiff.awk: \"" dir "\" isn't a directory.\n\n");
      exit_flag = 1;
      exit(1);
    }
}


function check_external_executables() {
  # You only need a gui if debug is off.  Default to "mgdiff" if
  # the user does not pass in a value.
  if(use_gui && !rmgdiff_gui)
    {
      rmgdiff_gui = "mgdiff";
    }
  check_exec(rmgdiff_gui);

  if(!file_cmd)
    {
      file_cmd = "file";
    }
  check_exec(file_cmd);

  check_dir(dir1);
  check_dir(dir2);
}

#
# get_full_names(raw_diff_line, dir1, dir2, full_names)
#     -- This function takes the raw output of "diff -rq" for lines of
#        the form "... <file1> and <file2> differ" and returns <file1>
#        and <file2> in "full_names[1]" and "full_names[2]" respectively.
#        A special function is needed in order to account for those
#        cases where the file names have embedded spaces.
#
function get_full_names(raw_diff_line, dir1, dir2, full_names  ,  regex) {
  #
  # full_names[2] -- The first call to gsub() strips off the trailing
  # "differ".  The second call to gsub() strips from the beginning of
  # the string to the "and" that precedes <file2>.  In case you missed
  # it, we are calculating full_names[2] [sic] first.
  #
  full_names[2] = raw_diff_line;
  gsub(/ differ$/, "", full_names[2]);
  gsub("^.* and (" dir2 ")", dir2, full_names[2]);

  #
  # full_names[1] -- The first call to gsub() strips off the trailing
  # "and <file2> differ".  The second call to gsub() strips from the
  # beginning of the string up to <file1>.
  #
  full_names[1] = raw_diff_line;
  sub(" and " full_names[2] " differ$", "", full_names[1]);
  sub("^.* " dir1, dir1, full_names[1]);

  if( debug ) {
      print("full_names[1] = " full_names[1]);
      print("full_names[2] = " full_names[2]);
  }
}



BEGIN {
  if( debug )
    print("Start BEGIN");

  if( version )
    {
      printf("\nrmgdiff.awk: v1.8.1\n\n");
      exit_flag = 1;
      exit 1;
    }

  first_diff = 1;            # Flag.

  check_external_executables();

  if( debug )
    {
      print("dir1 = " dir1);
      print("dir2 = " dir2);
    }

  dir1 = trim_dir(dir1);
  dir2 = trim_dir(dir2);

  if( debug )
    {
      print("Trimmed dir1 to " dir1);
      print("Trimmed dir2 to " dir2);
      print("");
    }

  # When you want to match regular expressions, you need to escape any
  # meta characters.  For example, if your directory where "c++_src",
  # and you try to do the match in the /^Only in/ that checks the
  # following:
  # 
  #       if( "c++_src" ~ "^" "c++_src" )
  #
  # it will fail because the "++" in the last term are meta characters
  # that aren't matched.
  dir1_escaped = escape_dir(dir1);
  dir2_escaped = escape_dir(dir2);

  if( debug )
    {
      print("dir1 escaped to " dir1_escaped);
      print("dir2 escaped to " dir2_escaped);
    }

  if( length(dir1_escaped) >= length(dir2_escaped) ) {
    longer_dir = dir1;
    longer_dir_escaped = dir1_escaped;
    shorter_dir = dir2;
    shorter_dir_escaped = dir2_escaped;
  } else {
    longer_dir = dir2;
    longer_dir_escaped = dir2_escaped;
    shorter_dir = dir1;
    shorter_dir_escaped = dir1_escaped;
  }

  if( debug )
    {
      print("longer_dir = " longer_dir);
      print("longer_dir_escaped = " longer_dir_escaped);
      print("shorter_dir = " shorter_dir);
      print("shorter_dir_escaped = " shorter_dir_escaped);
    }

}


{
  # Show the current line.
  if( debug )
    print("Current line:  " $0);
}



# Find the files that differ.  Filter out the VCS entries.  Call mgdiff
# if the file is a text file.  If the file is a binary, save it for later.
/^Files / {
  if( debug )
    print("Start Text and Binary files");

  if( !use_cvs && $0 ~ /[ \/](CVS|.bzr|.git|.svn)([ \/:]|$)/ )
    {
      if( debug )
        print("Skipping VCS file.\n");
      next;
    }

  full_names[1] = "";
  full_names[2] = "";
  get_full_names($0, dir1, dir2, full_names);

  add_text_or_binary(full_names[1], full_names[2]);
}


# This is here for compatibility with the older version of GNU diff
# that reported binary and text file differences separately.
/^Binary files / {
  if( debug )
    print("Start Binary files only");

  if( !use_cvs && $0 ~ /[ \/](CVS|.bzr|.git|.svn)([ \/:]|$)/ )
    {
      if( debug )
        print("Skipping VCS file.\n");
      next;
    }

  full_names[1] = "";
  full_names[2] = "";
  get_full_names($0, dir1, dir2, full_names);

  add_binary(full_names[1], full_names[2]);
}

# Find the files that are only in one of the directories.  Filter out
# the VCS entries.  Sort into two arrays for later printing.
/^Only in / {
  if( debug )
    print("Start Only in");

  if( !use_cvs && $0 ~ /[ \/](CVS|.bzr|.git|.svn)([ \/:]|$)/ )
    {
      if( debug )
        print("Skipping VCS file.\n");
      next;
    }

  # Find the directory.
  only_in_dir = substr($0, length("Only in ") + 1);
  gsub(/: .*$/, "", only_in_dir);

  # Find the file that is only in "only_in_dir".
  only_file = $0;
  gsub(/^.*: /, "", only_file);

  if( debug )
    {
      print("only_in_dir = " only_in_dir);
      print("only_file = " only_file);
    }

  #
  # A space means to concatenate the strings.  So,
  #
  #        only_in_dir ~ "^" longer_dir_escaped
  #
  #
  # means you have a match if only_in_dir begins with longer_dir_escaped.
  #
  # You have to NOT anchor the end of the string to match.  The reason
  # is that you could easily get the situation where a file or
  # directory is only in one of the directories you are recursively
  # diffing, and it has a depth of 2 or more.  (Note, "depth" here is
  # the same concept as the "find" command's "-maxdepth" parameter.)
  # This means you don't know what is going to be at the end of only_in_dir.
  #
  # You have to test the longer directory first because you might be
  # diffing two directories named something like "my_dir" and
  # "my_dir-v1.0".  If you tested the shorter directory first, you
  # would always get a match because when only_in_dir is the longer directory,
  # it too matches the shorter directory.
  #

  if( only_in_dir ~ "^" longer_dir_escaped ) {
      add_only_in(longer_dir, only_in_dir, only_file);
  }
  else if( only_in_dir ~ "^" shorter_dir_escaped ) {
      add_only_in(shorter_dir, only_in_dir, only_file);
  } else {
      print("***");
      print("*** rmgdiff.awk: Internal error.  Missed an \"only in\".");
      print("***    only_in_dir = " only_in_dir);
      print("***");
      exit_flag = 1;
      exit(1);
    }

}


# Just print a line to separate output for each pass.
{
  if( debug )
    print("");
}


# Print out the entries you earlier saved to an array.
END {
  if( !exit_flag )
    {

      # I decided to not create a separate function for printing
      # reports because you can't pass these potentially large
      # arrays by reference.

      if( executable_files_cnt )
        {
          printf("\n*** DIFFERENT EXECUTABLES ***\n\n");
          for( i = 0 ; i < executable_files_cnt ; i++ )
            print(executable_files[i]);
        }

      if( shared_libs_cnt )
        {
          printf("\n*** DIFFERENT SHARED LIBRARIES ***\n\n");
          for( i = 0 ; i < shared_libs_cnt ; i++ )
            print(shared_libs[i]);
        }

      if( static_libs_cnt )
        {
          printf("\n*** DIFFERENT STATIC LIBRARIES ***\n\n");
          for( i = 0 ; i < static_libs_cnt ; i++ )
            print(static_libs[i]);
        }

      if( object_files_cnt )
        {
          printf("\n*** DIFFERENT OBJECT FILES ***\n\n");
          for( i = 0 ; i < object_files_cnt ; i++ )
            print(object_files[i]);
        }

      if( other_bin_files_cnt )
        {
          printf("\n*** OTHER DIFFERENT BINARY FILES ***\n\n");
          for( i = 0 ; i < other_bin_files_cnt ; i++ )
            print(other_bin_files[i]);
        }
      
      if( only_in_dir1_cnt )
        {
          printf("\n*** FILES ONLY IN %s ***\n\n", dir1);
          for( i = 0 ; i < only_in_dir1_cnt ; i++ )
            print(only_in_dir1[i]);
        }
      
      if( only_in_dir2_cnt )
        {
          printf("\n*** FILES ONLY IN %s ***\n\n", dir2);
          for( i = 0 ; i < only_in_dir2_cnt ; i++ )
            print(only_in_dir2[i]);
        }

      if( mismatched_files_cnt )
        {
          printf("\n*** WARNING: MISMATCHED FILES ***\n\n");
          for( i = 0 ; i < mismatched_files_cnt ; i++ )
            print(mismatched_files[i]);
        }

      print("");
    }
}
