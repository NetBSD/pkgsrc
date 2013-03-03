$NetBSD: patch-library_grt_src_grtpp__shell__lua__help.cpp,v 1.1 2013/03/03 04:54:26 joerg Exp $

--- library/grt/src/grtpp_shell_lua_help.cpp.orig	2013-02-28 22:30:44.000000000 +0000
+++ library/grt/src/grtpp_shell_lua_help.cpp
@@ -57,7 +57,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
   {
     "quit",
     "Quits the application. Instead of quit the synonym 'exit' can be used.",
-    "quit"NL
+    "quit" NL
       "exit",
     NULL,
     NULL,
@@ -66,7 +66,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
   {
     "exit",
     "Quits the application. 'exit' is a synonym for 'quit'.",
-    "quit"NL
+    "quit" NL
       "exit",
     NULL,
     NULL,
@@ -78,18 +78,18 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
       "printed. ls can also be used to list the items stored in a Lua table (-t) or "
       "to print information about the available GRT modules.",
     "ls [-t luaTable | -m [moduleName] | -s [structName]]",
-    "-t             Prints a list of all items of the given Lua table."NL
-      "luaTable       The Lua table to be printed."NL
-      "-m             Prints a list of all available GRT modules."NL
-      "moduleName     If a module name is specified, a list of functions the module"NL
-      "-s             Prints a list of all available GRT structs."NL
-      "structName     If a struct name is specfiied, a list of member variables"NL
+    "-t             Prints a list of all items of the given Lua table." NL
+      "luaTable       The Lua table to be printed." NL
+      "-m             Prints a list of all available GRT modules." NL
+      "moduleName     If a module name is specified, a list of functions the module" NL
+      "-s             Prints a list of all available GRT structs." NL
+      "structName     If a struct name is specfiied, a list of member variables" NL
       "               contains is printed.",
-    "  ls -t grtV"NL
-      "               Lists all entries of te grtV Lua table."NL
-      "  ls -m"NL
-      "               Lists all available GRT modules."NL
-      "  ls -m Base"NL
+    "  ls -t grtV" NL
+      "               Lists all entries of te grtV Lua table." NL
+      "  ls -m" NL
+      "               Lists all available GRT modules." NL
+      "  ls -m Base" NL
       "               Lists the functions of the GRT module 'Base'",
     "  help cd, help show, help table, help grtM"
   },
@@ -99,17 +99,17 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
       "the GRT shell prompt and is used for the ls and show shell commands. If cd "
       "is called without parameters the current global object path is printed.",
     "cd [objectName | .. | path]",
-    "objectName     The name of the object to change into relative from the"NL
-      "               current path."NL
-      "..             Goes up one object relative to the current path."NL
-      "path           Absolute (starting with /) or relative path (starting with ./)"NL
+    "objectName     The name of the object to change into relative from the" NL
+      "               current path." NL
+      "..             Goes up one object relative to the current path." NL
+      "path           Absolute (starting with /) or relative path (starting with ./)" NL
       "               path of the object to make the new current global object.",
-    "  cd Migration"NL
-      "               Changes the current global object to ./Migration. If the current"NL
-      "               global object has been e.g. '/app' it is changed to "NL
-      "               '/app/Migration'."NL
-      "  cd .."NL
-      "               If the current global object has been e.g. '/app/Migration' it is"NL
+    "  cd Migration" NL
+      "               Changes the current global object to ./Migration. If the current" NL
+      "               global object has been e.g. '/app' it is changed to " NL
+      "               '/app/Migration'." NL
+      "  cd .." NL
+      "               If the current global object has been e.g. '/app/Migration' it is" NL
       "               changed to '/app'.",
     "  help ls, help show"
   },
@@ -117,14 +117,14 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "show",
     "Prints the current global object or the object with the given path.",
     "show [path]",
-    "path           The absolut (starting with /) or relative (starting with ./) path"NL
+    "path           The absolut (starting with /) or relative (starting with ./) path" NL
       "               of the object to print.",
-    "  cd Migration"NL
-      "               Changes the current global object to ./Migration. If the current"NL
-      "               global object has been e.g. '/app' it is changed to "NL
-      "               '/app/Migration'."NL
-      "  cd .."NL
-      "               If the current global object has been e.g. '/app/Migration' it is"NL
+    "  cd Migration" NL
+      "               Changes the current global object to ./Migration. If the current" NL
+      "               global object has been e.g. '/app' it is changed to " NL
+      "               '/app/Migration'." NL
+      "  cd .." NL
+      "               If the current global object has been e.g. '/app/Migration' it is" NL
       "               changed to '/app'.",
     "  help ls, help show"
   },
@@ -133,7 +133,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Load and execute a lua script file.",
     "run filename",
     "filename       File that should be loaded and executed.",
-    "  run scripts/test.lua"NL
+    "  run scripts/test.lua" NL
       "               Runs the script scripts/test.lua.",
     NULL
   },
@@ -142,22 +142,22 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Used for fast access to global objects. /path is converted to grtV.getGlobal() "
       "and grtV.setGlobal() by the shell's preprocessor. Please note that you cannot "
       "use /path in scripts.",
-    "/path = var                 Assigns the Lua variable var to the global object "NL
-      "                            defined by /path."NL
-      "//path with spaces/ = var   Assigns the Lua variable var to the global object "NL
-      "                            defined by /path if the path contains spaces."NL
-      "var = /path                 Assigns the global object defined by /path to then "NL
-      "                            Lua variable var."NL
-      "var = //path with space/    Assigns the global object defined by /path to then "NL
+    "/path = var                 Assigns the Lua variable var to the global object " NL
+      "                            defined by /path." NL
+      "//path with spaces/ = var   Assigns the Lua variable var to the global object " NL
+      "                            defined by /path if the path contains spaces." NL
+      "var = /path                 Assigns the global object defined by /path to then " NL
+      "                            Lua variable var." NL
+      "var = //path with space/    Assigns the global object defined by /path to then " NL
       "                            Lua variable var whifen the path contains spaces.",
     NULL,
-    "  /test= 27"NL
-      "               Assigns the number 27 to the global object with the path '/test'."NL
-      "  //test object/= \"testing\""NL
-      "               Assigns the string \"testing\" to the global object with the path"NL
-      "               '/test object'."NL
-      "  catalog= /migration/srcCatalog"NL
-      "               Assigns the global object with the path '/migration/srcCatalog'"NL
+    "  /test= 27" NL
+      "               Assigns the number 27 to the global object with the path '/test'." NL
+      "  //test object/= \"testing\"" NL
+      "               Assigns the string \"testing\" to the global object with the path" NL
+      "               '/test object'." NL
+      "  catalog= /migration/srcCatalog" NL
+      "               Assigns the global object with the path '/migration/srcCatalog'" NL
       "               to the Lua variable catalog",
     "  help ls, help cd"
   },
@@ -241,14 +241,14 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "input",
     "Promnts for a keyboard input.",
     "input (str)",
-    "str            String that will be printed before the input prompt"NL,
-    "  res= input(\"Please enter a number form the list:\")"NL
+    "str            String that will be printed before the input prompt" NL,
+    "  res= input(\"Please enter a number form the list:\")" NL
     "               Asks the user to enter a number and stores it in the variable res",
     NULL
   },
   {
     "ipairs",
-    "Returns an iterator function, the table t, and 0, so that the construction"NL"  for i,v in ipairs(t) do ... end"NL"will iterate over the pairs (1,t[1]), (2,t[2]), ..., up to the first integer key with a nil value in the table.",
+    "Returns an iterator function, the table t, and 0, so that the construction" NL "  for i,v in ipairs(t) do ... end" NL "will iterate over the pairs (1,t[1]), (2,t[2]), ..., up to the first integer key with a nil value in the table.",
     "ipairs (t)",
     NULL,
     NULL,
@@ -272,7 +272,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
   },
   {
     "loadstring",
-    "Loads a string as a Lua chunk (without running it). If there are no errors, returns the compiled chunk as a function; otherwise, returns nil plus the error message. The environment of the returned function is the global environment. The optional parameter chunkname is the name to be used in error messages and debug information. To load and run a given string, use the idiom"NL"  assert(loadstring(s))()",
+    "Loads a string as a Lua chunk (without running it). If there are no errors, returns the compiled chunk as a function; otherwise, returns nil plus the error message. The environment of the returned function is the global environment. The optional parameter chunkname is the name to be used in error messages and debug information. To load and run a given string, use the idiom" NL "  assert(loadstring(s))()",
     "loadlib (libname, funcname)",
     NULL,
     NULL,
@@ -288,7 +288,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
   },
   {
     "pairs",
-    "Returns the next function and the table t (plus a nil), so that the construction"NL"  for k,v in pairs(t) do ... end"NL"will iterate over all key-value pairs of table t.",
+    "Returns the next function and the table t (plus a nil), so that the construction" NL "  for k,v in pairs(t) do ... end" NL "will iterate over all key-value pairs of table t.",
     "pairs (t)",
     NULL,
     NULL,
@@ -362,8 +362,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "sleep",
     "Pauses the execution of the script for ms milliseconds.",
     "sleep (ms)",
-    "ms             Time to sleep in ms."NL,
-    "  sleep(1000)"NL
+    "ms             Time to sleep in ms." NL,
+    "  sleep(1000)" NL
     "               Sleeps for one second.",
     NULL
   },
@@ -393,7 +393,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
   },
   {
     "unpack",
-    "Returns all elements from the given list. This function is equivalent to \"NL\"  return list[1], list[2], ..., list[n]"NL"except that the above code can be written only for a fixed n. The number n is the size of the list, as defined for the table.getn function.",
+    "Returns all elements from the given list. This function is equivalent to \"NL\"  return list[1], list[2], ..., list[n]" NL "except that the above code can be written only for a fixed n. The number n is the size of the list, as defined for the table.getn function.",
     "unpack (list)",
     NULL,
     NULL,
@@ -476,7 +476,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns a new generated GUID as lua string.",
     "grt.newGuid()",
     NULL,
-    "  print(grt.newGuid())"NL
+    "  print(grt.newGuid())" NL
       "               Prints a new generated GUID.",
     NULL
   },
@@ -492,7 +492,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "split",
     "Splits the given Lua string based on the separator and puts the tokens into a Lua list.",
     "function grt.split(str, sep)",
-    "str            the string to split"NL
+    "str            the string to split" NL
       "sep            the separator character",
     NULL,
     NULL
@@ -653,9 +653,9 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns a formatted version of its variable number of arguments following the description given in its first argument (which must be a string). The format string follows the same rules as the printf family of standard C functions. The only differences are that the options/modifiers *, l, L, n, p, and h are not supported, and there is an extra option, q. The q option formats a string in a form suitable to be safely read back by the Lua interpreter: The string is written between double quotes, and all double quotes, newlines, and backslashes in the string are correctly escaped when written. The options c, d, E, e, f, g, G, i, o, u, X, and x all expect a number as argument, whereas q and s expect a string. The * modifier can be simulated by building the appropriate format string. For example, \"%*g\" can be simulated with \"%\"..width..\"g\". String values to be formatted with %s cannot contain embedded zeros.",
     "string.format (formatstring, e1, e2, ...)",
     NULL,
-    "  string.format('%q', 'a string with \"quotes\" and \n new line')"NL
-      "             will produce the string:"NL
-      "\"a string with \\\"quotes\\\" and \\"NL
+    "  string.format('%q', 'a string with \"quotes\" and \n new line')" NL
+      "             will produce the string:" NL
+      "\"a string with \\\"quotes\\\" and \\" NL
       " new line\"",
     NULL
   },
@@ -664,17 +664,17 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns an iterator function that, each time it is called, returns the next captures from pattern pat over string s. If pat specifies no captures, then the whole match is produced in each call.",
     "string.gfind (s, pat)",
     NULL,
-    "  s = \"hello world from Lua\""NL
-      "  for w in string.gfind(s, \"%a+\") do"NL
-      "    print(w)"NL
-      "  end"NL
-      "               will iterate over all the words from string s, printing"NL
-      "               one per line. The next example collects all pairs key=value"NL
-      "               from the given string into a table:"NL
-      "  t = {}"NL
-      "  s = \"from=world, to=Lua\""NL
-      "  for k, v in string.gfind(s, \"(%w+)=(%w+)\") do"NL
-      "    t[k] = v"NL
+    "  s = \"hello world from Lua\"" NL
+      "  for w in string.gfind(s, \"%a+\") do" NL
+      "    print(w)" NL
+      "  end" NL
+      "               will iterate over all the words from string s, printing" NL
+      "               one per line. The next example collects all pairs key=value" NL
+      "               from the given string into a table:" NL
+      "  t = {}" NL
+      "  s = \"from=world, to=Lua\"" NL
+      "  for k, v in string.gfind(s, \"(%w+)=(%w+)\") do" NL
+      "    t[k] = v" NL
       "  end",
     NULL
   },
@@ -683,28 +683,28 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns a copy of s in which all occurrences of the pattern pat have been replaced by a replacement string specified by repl. gsub also returns, as a second value, the total number of substitutions made. If repl is a string, then its value is used for replacement. Any sequence in repl of the form %n, with n between 1 and 9, stands for the value of the n-th captured substring (see below). If repl is a function, then this function is called every time a match occurs, with all captured substrings passed as arguments, in order; if the pattern specifies no captures, then the whole match is passed as a sole argument. If the value returned by this function is a string, then it is used as the replacement string; otherwise, the replacement string is the empty string. The optional last parameter n limits the maximum number of substitutions to occur. For instance, when n is 1 only the first occurrence of pat is replaced.",
     "string.gsub (s, pat, repl [, n])",
     NULL,
-    "  x = string.gsub(\"hello world\", \"(%w+)\", \"%1 %1\")"NL
-      "  --> x=\"hello hello world world\""NL
+    "  x = string.gsub(\"hello world\", \"(%w+)\", \"%1 %1\")" NL
+      "  --> x=\"hello hello world world\"" NL
       NL
-      "  x = string.gsub(\"hello world\", \"(%w+)\", \"%1 %1\", 1)"NL
-      "  --> x=\"hello hello world\""NL
+      "  x = string.gsub(\"hello world\", \"(%w+)\", \"%1 %1\", 1)" NL
+      "  --> x=\"hello hello world\"" NL
       NL
-      "  x = string.gsub(\"hello world from Lua\", \"(%w+)%s*(%w+)\", \"%2 %1\")"NL
-      "  --> x=\"world hello Lua from\""NL
+      "  x = string.gsub(\"hello world from Lua\", \"(%w+)%s*(%w+)\", \"%2 %1\")" NL
+      "  --> x=\"world hello Lua from\"" NL
       NL
-      "  x = string.gsub(\"home = $HOME, user = $USER\", \"%$(%w+)\", os.getenv)"NL
-      "  --> x=\"home = /home/roberto, user = roberto\""NL
+      "  x = string.gsub(\"home = $HOME, user = $USER\", \"%$(%w+)\", os.getenv)" NL
+      "  --> x=\"home = /home/roberto, user = roberto\"" NL
       NL
-      "  x = string.gsub(\"4+5 = $return 4+5$\", \"%$(.-)%$\", function (s)"NL
-      "        return loadstring(s)()"NL
-      "      end)"NL
-      "  --> x=\"4+5 = 9\""NL
+      "  x = string.gsub(\"4+5 = $return 4+5$\", \"%$(.-)%$\", function (s)" NL
+      "        return loadstring(s)()" NL
+      "      end)" NL
+      "  --> x=\"4+5 = 9\"" NL
       NL
-      "  local t = {name=\"lua\", version=\"5.0\"}"NL
-      "  x = string.gsub(\"$name_$version.tar.gz\", \"%$(%w+)\", function (v)"NL
-      "        return t[v]"NL
-      "      end)"NL
-      "  --> x=\"lua_5.0.tar.gz\""NL,
+      "  local t = {name=\"lua\", version=\"5.0\"}" NL
+      "  x = string.gsub(\"$name_$version.tar.gz\", \"%$(%w+)\", function (v)" NL
+      "        return t[v]" NL
+      "      end)" NL
+      "  --> x=\"lua_5.0.tar.gz\"" NL,
     NULL
   },
   {
@@ -1028,9 +1028,9 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Opens the given file name in read mode and returns an iterator function that, each time it is called, returns a new line from the file.",
     "io.lines ([filename])",
     NULL,
-    "  for line in io.lines(filename) do ... end"NL
-      "               This construction will iterate over all lines of the file."NL
-      "               When the iterator function detects the end of file, it returns"NL
+    "  for line in io.lines(filename) do ... end" NL
+      "               This construction will iterate over all lines of the file." NL
+      "               When the iterator function detects the end of file, it returns" NL
       "               nil (to finish the loop) and automatically closes the file.",
     NULL
   },
@@ -1038,14 +1038,14 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "open",
     "This function opens a file, in the mode specified in the string mode. It returns a new file handle, or, in case of errors, nil plus an error message. The mode string may also have a b at the end, which is needed in some systems to open the file in binary mode. This string is exactly what is used in the standard C function fopen.",
     "io.open (filename [, mode])",
-    "filename         Name of the file to open."NL
-      "mode             The mode string can be any of the following:"NL
-      "                 \"r\" read mode (the default);"NL
-      "                 \"w\" write mode;"NL
-      "                 \"a\" append mode;"NL
-      "                 \"r+\" update mode, all previous data is preserved;"NL
-      "                 \"w+\" update mode, all previous data is erased;"NL
-      "                 \"a+\" append update mode, previous data is preserved, writing is"NL
+    "filename         Name of the file to open." NL
+      "mode             The mode string can be any of the following:" NL
+      "                 \"r\" read mode (the default);" NL
+      "                 \"w\" write mode;" NL
+      "                 \"a\" append mode;" NL
+      "                 \"r+\" update mode, all previous data is preserved;" NL
+      "                 \"w+\" update mode, all previous data is erased;" NL
+      "                 \"a+\" append update mode, previous data is preserved, writing is" NL
       "                 only allowed at the end of file.",
     NULL,
     NULL
@@ -1123,8 +1123,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns an iterator function that, each time it is called, returns a new line from the file.",
     "file:lines ()",
     NULL,
-    "  for line in file:lines() do ... end"NL
-      "               will iterate over all lines of the file. (Unlike io.lines,"NL
+    "  for line in file:lines() do ... end" NL
+      "               will iterate over all lines of the file. (Unlike io.lines," NL
       "               this function does not close the file when the loop ends.)",
     NULL
   },
@@ -1132,15 +1132,15 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "read",
     "Reads the file file, according to the given formats, which specify what to read. For each format, the function returns a string (or a number) with the characters read, or nil if it cannot read data with the specified format. When called without formats, it uses a default format that reads the entire next line.",
     "file:read (format1, ...)",
-    "format1            The available formats are:"NL
-      "                   \"*n\" reads a number; this is the only format that returns a"NL
-      "                   number instead of a string."NL
-      "                   \"*a\" reads the whole file, starting at the current position."NL
-      "                   On end of file, it returns the empty string."NL
-      "                   \"*l\" reads the next line (skipping the end of line), "NL
-      "                   returning nil on end of file. This is the default format."NL
-      "                   number reads a string with up to that number of characters,"NL
-      "                   returning nil on end of file. If number is zero, it reads"NL
+    "format1            The available formats are:" NL
+      "                   \"*n\" reads a number; this is the only format that returns a" NL
+      "                   number instead of a string." NL
+      "                   \"*a\" reads the whole file, starting at the current position." NL
+      "                   On end of file, it returns the empty string." NL
+      "                   \"*l\" reads the next line (skipping the end of line), " NL
+      "                   returning nil on end of file. This is the default format." NL
+      "                   number reads a string with up to that number of characters," NL
+      "                   returning nil on end of file. If number is zero, it reads" NL
       "                   nothing and returns an empty string, or nil on end of file.",
     NULL,
     NULL
@@ -1149,8 +1149,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "seek",
     "Sets and gets the file position, measured from the beginning of the file, to the position given by offset plus a base specified by the string whence. In case of success, function seek returns the final file position, measured in bytes from the beginning of the file. If this function fails, it returns nil, plus a string describing the error. The default value for whence is \"cur\", and for offset is 0. Therefore, the call file:seek() returns the current file position, without changing it; the call file:seek(\"set\") sets the position to the beginning of the file (and returns 0); and the call file:seek(\"end\") sets the position to the end of the file, and returns its size.",
     "file:seek ([whence] [, offset])",
-    "whence             \"set\" base is position 0 (beginning of the file);"NL
-      "                   \"cur\" base is current position;"NL
+    "whence             \"set\" base is position 0 (beginning of the file);" NL
+      "                   \"cur\" base is current position;" NL
       "                   \"end\" base is end of file;",
     NULL,
     NULL
@@ -1196,8 +1196,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns the number of seconds from time t1 to time t2. In Posix, Windows, and some other systems, this value is exactly t2-t1.",
     "os.difftime (t2, t1)",
     NULL,
-    "  for line in file:lines() do ... end"NL
-      "               will iterate over all lines of the file. (Unlike io.lines,"NL
+    "  for line in file:lines() do ... end" NL
+      "               will iterate over all lines of the file. (Unlike io.lines," NL
       "               this function does not close the file when the loop ends.)",
     NULL
   },
@@ -1213,8 +1213,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "exit",
     "Calls the C function exit, with an optional code, to terminate the host program. The default value for code is the success code.",
     "os.exit ([code])",
-    "whence             \"set\" base is position 0 (beginning of the file);"NL
-      "                   \"cur\" base is current position;"NL
+    "whence             \"set\" base is position 0 (beginning of the file);" NL
+      "                   \"cur\" base is current position;" NL
       "                   \"end\" base is end of file;",
     NULL,
     NULL
@@ -1284,7 +1284,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Clears the given list.",
     "grtV.clearList (list)",
     "list         the GRT list to clear.",
-    "  grtV.clearList(pluginList)"NL
+    "  grtV.clearList(pluginList)" NL
       "               will clear the list pluginList",
     NULL
   },
@@ -1292,10 +1292,10 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "child",
     "Returns a child object defined by a subpath.",
     "grtV.child (grtObj, path)",
-    "grtObj         the GRT object that contains the child object."NL
+    "grtObj         the GRT object that contains the child object." NL
       "path           the relative path to the child object.",
-    "  res= grtV.child(grtV.getGlobal(\"/rdbmsMgmt\"), \"/storedConns/0\")"NL
-      "               will return the first stored connection from the "NL
+    "  res= grtV.child(grtV.getGlobal(\"/rdbmsMgmt\"), \"/storedConns/0\")" NL
+      "               will return the first stored connection from the " NL
       "               global \"/rdbmsMgmt\" object.",
     NULL
   },
@@ -1362,8 +1362,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns the dict's key with the given index.",
     "grtV.getKey (grtDict, index)",
     "grtDict        The GRT dict to check.",
-    "  rdbmsMgmt= RdbmsManagement:getManagementInfo()"NL
-    "  print(grtV.getKey(rdbmsMgmt.rdbms[1].drivers[1].defaultModules, 1))"NL
+    "  rdbmsMgmt= RdbmsManagement:getManagementInfo()" NL
+    "  print(grtV.getKey(rdbmsMgmt.rdbms[1].drivers[1].defaultModules, 1))" NL
       "               Prints the first key of the defaultModules dict.",
     NULL
   },
@@ -1371,7 +1371,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "getListItemByObjName",
     "Returns a list item object based on its name.",
     "grtV.getListItemByObjName (grtList, \"name\")",
-    "grtList        The GRT list to check."NL
+    "grtList        The GRT list to check." NL
       "name           The object name to search",
     NULL,
     NULL
@@ -1381,8 +1381,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns the number of entries in the given list or dict.",
     "grtV.getn (grtValue)",
     "grtList        The GRT list or dict to check.",
-    "  print(grtV.getn(grtV.getGlobal(\"/rdbmsMgmt/storedConns\")))"NL
-      "               Returns the number of items in the global"NL
+    "  print(grtV.getn(grtV.getGlobal(\"/rdbmsMgmt/storedConns\")))" NL
+      "               Returns the number of items in the global" NL
       "               \"/rdbmsMgmt/storedConns\" list",
     NULL
   },
@@ -1390,9 +1390,9 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "getGlobal",
     "Returns the global GRT object at the given path. Global objects are referred by a tree that can be accessed from all languages bound to the GRT.",
     "grtV.getGlobal (path)",
-    "path           The path to the global object"NL,
-    "  grtV.getGlobal(\"/rdbmsMgmt/storedConns/0\")"NL
-    "               Returns the GRT object at the global path "NL
+    "path           The path to the global object" NL,
+    "  grtV.getGlobal(\"/rdbmsMgmt/storedConns/0\")" NL
+    "               Returns the GRT object at the global path " NL
     "               \"/rdbmsMgmt/storedConns/0\"",
     NULL
   },
@@ -1400,10 +1400,10 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "insert",
     "Inserts the given obj into the grtList. If index is ommited, the obj will be inserted at the very end of the list.",
     "grtV.insert (grtList, obj [, index])",
-    "grtList        The GRT list that will hold the obj."NL
-      "obj            the object to insert."NL
+    "grtList        The GRT list that will hold the obj." NL
+      "obj            the object to insert." NL
       "index          optional index of where to insert the obj in the list",
-    "  grtV.insert(rdbmsMgmt.rdbms, rdbms)"NL
+    "  grtV.insert(rdbmsMgmt.rdbms, rdbms)" NL
       "               appends the rdbms object to the rdbmsMgmt.rdbms list.",
     NULL
   },
@@ -1412,10 +1412,10 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Loads and returns a GRT object from a file.",
     "grtV.load (filename)",
     "filename       Filename of the file to load",
-      "  if grt.fileExists(storedConnsFilename) then"NL
-      "    rdbmsMgmt.storedConns= grtV.load(storedConnsFilename)"NL
-      "  end"NL
-      "               Loads the file with the filename stored in"NL
+      "  if grt.fileExists(storedConnsFilename) then" NL
+      "    rdbmsMgmt.storedConns= grtV.load(storedConnsFilename)" NL
+      "  end" NL
+      "               Loads the file with the filename stored in" NL
       "               storedConnsFilename and assigns it to rdbmsMgmt.storedConns",
     NULL
   },
@@ -1423,13 +1423,13 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "newDict",
     "Creates a new GRT dict with the optional contentType and contentStructName.",
     "grtV.newDict (contentType, contentStructName)",
-    "contentType        If submitted a typed dict is created and the dict can only"NL
-      "                   hold members of the given type. Possible values are \"int\","NL
-      "                   \"string\", \"real\", \"list\", \"dict\""NL
-      "contentStructName  If the contentType is \"dict\" a struct name can be defined."NL
+    "contentType        If submitted a typed dict is created and the dict can only" NL
+      "                   hold members of the given type. Possible values are \"int\"," NL
+      "                   \"string\", \"real\", \"list\", \"dict\"" NL
+      "contentStructName  If the contentType is \"dict\" a struct name can be defined." NL
       "                   Only dicts with this struct name can be used as dict members.",
-    "  obj= grtV.newDict(\"dict\", \"db.Table\")"NL
-      "                   Creates a new dict that can only have dict members of the"NL
+    "  obj= grtV.newDict(\"dict\", \"db.Table\")" NL
+      "                   Creates a new dict that can only have dict members of the" NL
       "                   struct db.Table",
     NULL
   },
@@ -1437,25 +1437,25 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "newList",
     "Creates a new GRT list with the optional contentType and contentStructName.",
     "grtV.newList (contentType, contentStructName)",
-    "contentType        If submitted a typed list is created and the list can only"NL
-      "                   hold values of the given type. Possible values are \"int\","NL
-      "                   \"string\", \"real\", \"list\", \"dict\""NL
-      "contentStructName  If the contentType is \"dict\" a struct name can be defined."NL
+    "contentType        If submitted a typed list is created and the list can only" NL
+      "                   hold values of the given type. Possible values are \"int\"," NL
+      "                   \"string\", \"real\", \"list\", \"dict\"" NL
+      "contentStructName  If the contentType is \"dict\" a struct name can be defined." NL
       "                   Only dicts with this struct name can be added to the list.",
-    "  list= grtV.newList(\"string\")"NL
+    "  list= grtV.newList(\"string\")" NL
       "                   Creates a new list that can only hold string values",
     NULL
   },
   {
     "newObj",
-    "Creates a new GRT object initialized with the optional given values. All simple values"NL
-    "(\"int\", \"string\", \"real\") are initialized and all lists and dicts are created."NL
+    "Creates a new GRT object initialized with the optional given values. All simple values" NL
+    "(\"int\", \"string\", \"real\") are initialized and all lists and dicts are created." NL
     "Object references are left null.",
     "grtV.newObj (structName[, initValuesDict])",
-    "structName         Struct name of the object to create"NL
-    "initValuesDict     A dictionary containing initial values for object fields."NL,
-    "  rdbmsMgmt= grtV.newObj(\"db.mgmt.Management\", "NL
-    "    {name=\"rdbmsManagement\", owner=app})"NL
+    "structName         Struct name of the object to create" NL
+    "initValuesDict     A dictionary containing initial values for object fields." NL,
+    "  rdbmsMgmt= grtV.newObj(\"db.mgmt.Management\", " NL
+    "    {name=\"rdbmsManagement\", owner=app})" NL
     "                   Create a new object from the struct \"db.mgmt.Management\"",
     NULL
   },
@@ -1463,7 +1463,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "remove",
     "Removes the list item with the given index.",
     "grtV.remove (list, index)",
-    "list               GRT list to manipulate"NL
+    "list               GRT list to manipulate" NL
     "index              Index of the item to remove",
     NULL,
     NULL
@@ -1472,7 +1472,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "save",
     "Saves the given object to a file.",
     "grtV.save (obj, filename)",
-    "obj                The object to save."NL
+    "obj                The object to save." NL
       "filename           The name of the file to create",
     NULL,
     NULL
@@ -1481,11 +1481,11 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "setGlobal",
     "Assigns the object to the given global path.",
     "grtV.setGlobal (path, obj)",
-    "path               The global path that the object will be assigned to"NL
+    "path               The global path that the object will be assigned to" NL
       "obj                Object that will be assigned to the global path",
-    "  grtV.setGlobal(\"/rdbmsMgmt\", RdbmsManagement:getManagementInfo())"NL
-      "                   Calls the module function getManagementInfo() and"NL
-      "                   assignes the returned GRT value to the global path"NL
+    "  grtV.setGlobal(\"/rdbmsMgmt\", RdbmsManagement:getManagementInfo())" NL
+      "                   Calls the module function getManagementInfo() and" NL
+      "                   assignes the returned GRT value to the global path" NL
       "                   \"/rdbmsMgmt\"",
     NULL
   },
@@ -1494,8 +1494,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Converts the given GRT value to a Lua value.",
     "grtV.toLua (value)",
     "value              The GRT value to convert",
-    "  print(grtV.toLua(Base:getOsTypeName()))"NL
-      "                   Calls the module function getOsTypeName() and"NL
+    "  print(grtV.toLua(Base:getOsTypeName()))" NL
+      "                   Calls the module function getOsTypeName() and" NL
       "                   converts the returned GRT string to a Lua string.",
     NULL
   },
@@ -1511,7 +1511,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "typeOf",
     "Returns the type of a GRT value.",
     "typeName= grtV.typeOf (value)",
-    "value          a GRT value."NL
+    "value          a GRT value." NL
     "typeName       the name of the type: int, real, string, list, dict, object",
     NULL,
     NULL
@@ -1557,8 +1557,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns a Lua table containing all member names of the given struct name.",
     "grtS.getMembers (structName)",
     "structName         The name of the struct",
-    "  m= grtS.getMembers(\"db.Schema\")"NL
-      "  ls -t m"NL
+    "  m= grtS.getMembers(\"db.Schema\")" NL
+      "  ls -t m" NL
       "                   Lists all members of the struct \"db.Schema\"",
     NULL
   },
@@ -1566,9 +1566,9 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "getMemberType",
     "Returns the type of a member as Lua string.",
     "grtS.getMemberType (structName, memberName)",
-    "structName         The name of the struct"NL
+    "structName         The name of the struct" NL
       "memberName         The name of the member",
-    "  print(grtS.getMemberType(\"db.Schema\", \"tables\"))"NL
+    "  print(grtS.getMemberType(\"db.Schema\", \"tables\"))" NL
       "                   Prints the type of the member tables.",
     NULL
   },
@@ -1576,9 +1576,9 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "getMemberContentType",
     "Returns the content type of a member as Lua string.",
     "grtS.getMemberContentType (structName, memberName)",
-    "structName         The name of the struct"NL
+    "structName         The name of the struct" NL
       "memberName         The name of the member",
-    "  print(grtS.getMemberContentType(\"db.Schema\", \"tables\"))"NL
+    "  print(grtS.getMemberContentType(\"db.Schema\", \"tables\"))" NL
       "                   Prints the content type of the member tables.",
     NULL
   },
@@ -1586,9 +1586,9 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "getMemberContentStruct",
     "Returns the content struct name of a member as Lua string.",
     "grtS.getMemberContentStruct (structName, memberName)",
-    "structName         The name of the struct"NL
+    "structName         The name of the struct" NL
       "memberName         The name of the member",
-    "  print(grtS.getMemberContentStruct(\"db.Schema\", \"tables\"))"NL
+    "  print(grtS.getMemberContentStruct(\"db.Schema\", \"tables\"))" NL
       "                   Prints the content struct name of the member tables.",
     NULL
   },
@@ -1649,7 +1649,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "Returns all module names in a Lua table. If a extend is passed only modules that extend this module are returned.",
     "grtM.get ([extend])",
     NULL,
-    "  modules= grtM.get(\"RdbmsInfo\")"NL
+    "  modules= grtM.get(\"RdbmsInfo\")" NL
       "                   Returns all modules that extend \"RdbmsInfo\"",
     NULL
   },
@@ -1772,11 +1772,11 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "regExVal",
     "Evaluates the given regex against the text and returns the substring with the given subStringIndex",
     "grtU.regExVal (text, regex [, subStringIndex])",
-    "text               The text to search"NL
-      "regex              The regular expression to use"NL
+    "text               The text to search" NL
+      "regex              The regular expression to use" NL
       "subStringIndex     The Substring index to use, 1 if ommited",
-    "  print(regexVal(\"Int(10,5)\", "NL
-      "    \"(\\\\w*)\\\\s*(\\\\((\\\\d+)\\\\s*(\\\\,\\\\s*(\\\\d+))?\\\\))?\", 1))"NL
+    "  print(regexVal(\"Int(10,5)\", " NL
+      "    \"(\\\\w*)\\\\s*(\\\\((\\\\d+)\\\\s*(\\\\,\\\\s*(\\\\d+))?\\\\))?\", 1))" NL
       "                   Prints \"Int\"",
     NULL
   },
@@ -1784,8 +1784,8 @@ static MYX_GRT_SHELL_COMMAND_HELP_TEXT h
     "replace",
     "Replaces occurrences of the 'from' string to 'to' in the give text.",
     "grtU.replace (text, from , to)",
-    "text             The text to work on"NL
-    "from             The string to search"NL
+    "text             The text to work on" NL
+    "from             The string to search" NL
     "to               The string to replace with",
     "  print(replace(\"hello world\", \"hello\", \"bye\"))",
     NULL
@@ -1829,7 +1829,7 @@ static MYX_GRT_SHELL_COMMAND_HELP_GROUP 
   {
     "string",
     "String Manipulation",
-    "This library provides generic functions for string manipulation, such as finding"NL
+    "This library provides generic functions for string manipulation, such as finding" NL
     "and extracting substrings, and pattern matching.",
     help_string
   },
@@ -1933,9 +1933,9 @@ static void myx_grt_shell_show_command_h
         ul[k]= 0;
 
         grt->send_output(strfmt(NL
-          "%s - %s"NL
-          "%s"NL
-          "%s"NL
+          "%s - %s" NL
+          "%s" NL
+          "%s" NL
           NL,
           help_group.group_caption,
           help_group.group_name,
@@ -1958,7 +1958,7 @@ static void myx_grt_shell_show_command_h
         grt->send_output(dir);
 
         grt->send_output(strfmt(NL NL
-          "Type 'help %s.<command>' to get help on a specific command."NL,
+          "Type 'help %s.<command>' to get help on a specific command." NL,
           help_group.group_name));
 
         found= 1;
@@ -1979,7 +1979,7 @@ static void myx_grt_shell_show_command_h
               ul[k]= '-';
             ul[k]= 0;
 
-            grt->send_output(strfmt(NL"%s - %s.%s"NL, help_group.group_caption, help_group.group_name, help_text.cmd));
+            grt->send_output(strfmt(NL"%s - %s.%s" NL, help_group.group_caption, help_group.group_name, help_text.cmd));
             grt->send_output(ul);
             grt->send_output(NL);
 
@@ -2053,42 +2053,42 @@ void myx_grt_shell_show_help(grt::GRT *g
   if(!command || !*command)
   {
     grt->send_output(
-      "Shell Commands (only available in the GRT Shell)"NL
-      "--------------"NL
-      "help    (\\h)     Display this help."NL
-      "?       (\\?)     Synonym for 'help'."NL
-      "quit    (\\q)     Exit the shell."NL
-      "exit    (\\e)     Synonym for 'quit'."NL
-      "ls               List all objects in the current path, modules or tables."NL
-      "cd               Changes the current globals path"NL
-      "show             Prints an object"NL
-      "run     (\\r)     Load and execute a lua script file."NL
-      //"/path            Returns the global object at the given path"NL
+      "Shell Commands (only available in the GRT Shell)" NL
+      "--------------" NL
+      "help    (\\h)     Display this help." NL
+      "?       (\\?)     Synonym for 'help'." NL
+      "quit    (\\q)     Exit the shell." NL
+      "exit    (\\e)     Synonym for 'quit'." NL
+      "ls               List all objects in the current path, modules or tables." NL
+      "cd               Changes the current globals path" NL
+      "show             Prints an object" NL
+      "run     (\\r)     Load and execute a lua script file." NL
+      //"/path            Returns the global object at the given path" NL
       NL
-      "Global Functions and Objects"NL
-      "----------------------------"NL
-      "_G               Basic functions with a global scope"NL
-      //"grt              Library with common used functions for GRT scripting"NL
+      "Global Functions and Objects" NL
+      "----------------------------" NL
+      "_G               Basic functions with a global scope" NL
+      //"grt              Library with common used functions for GRT scripting" NL
       NL
-      "Lua Standard Libraries"NL
-      "----------------------"NL
-      "coroutine        Functions for collaborative multithreading"NL
-      "string           String manipulation functions"NL
-      "table            Generic functions for table manipulation"NL
-      "math             Mathematical functions"NL
-      "io               Input and Output Facilities"NL
-      "file             File class"NL
-      "os               Operating System Facilities"NL
+      "Lua Standard Libraries" NL
+      "----------------------" NL
+      "coroutine        Functions for collaborative multithreading" NL
+      "string           String manipulation functions" NL
+      "table            Generic functions for table manipulation" NL
+      "math             Mathematical functions" NL
+      "io               Input and Output Facilities" NL
+      "file             File class" NL
+      "os               Operating System Facilities" NL
       NL
-      "GRT Scripting Libraries"NL
-      "-----------------------"NL
-      "grtV             Library to work with GRT values"NL
-      "grtS             GRT struct management library"NL
-      "grtM             Library to return information about GRT modules"NL
-//      "grtA             GRT agent management library"NL
-      "grtU             GRT utility function library"NL
+      "GRT Scripting Libraries" NL
+      "-----------------------" NL
+      "grtV             Library to work with GRT values" NL
+      "grtS             GRT struct management library" NL
+      "grtM             Library to return information about GRT modules" NL
+//      "grtA             GRT agent management library" NL
+      "grtU             GRT utility function library" NL
       NL
-      "Type 'help <command/lib>' to get information about the command or library."NL
+      "Type 'help <command/lib>' to get information about the command or library." NL
       );
   }
   else
