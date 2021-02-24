#!/usr/bin/awk -f
# $NetBSD: genreadme.awk,v 1.47 2021/02/24 08:16:32 nia Exp $
#
# Copyright (c) 2002-2021 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Dan McMahill.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#


# Global variables
#-----------------
# The following associative arrays are used for storing the dependency
# information and other information for the packages
#
# depends[]  : index=pkgdir (math/scilab)
#                 List of explicitly listed depencencies by name.
#                 I.e.  "xless-[0-9]* pvm-3.4.3"
#
# builddepends[]  : index=pkgdir (math/scilab)
#                 List of explicitly listed depencencies by name.
#
BEGIN {
	do_pkg_readme=1;
# set to 1 to use "README-new.html" as the name
	use_readme_new=0;
	if (use_readme_new) {
		readme_name = "README-new.html";
	}
	else {
		readme_name = "README.html";
	}
	printf("Reading database file\n");
}

#conflicts /usr/pkgsrc/math/scilab
#depends /usr/pkgsrc/math/scilab xless-[0-9]*:../../x11/xless pvm-3.4.3:../../parallel/pvm3
#

/^(build_|tool_)?depends / {
#
# Read in the entire depends tree
# These lines look like:
#
#depends /usr/pkgsrc/math/scilab xless-[0-9]*:../../x11/xless pvm-3.4.3:../../parallel/pvm3
#build_depends /usr/pkgsrc/math/scilab libtool-base>=1.4.20010614nb9:../../devel/libtool-base
#
	deptype=$1;
#    pkg=fulldir2pkgdir($2);
	pkg = $2;
	if (pkg in depends) {}
	else {depends[pkg] = "";}
	if (pkg in builddepends) {}
	else {builddepends[pkg] = "";}

	for (i = 3; i <= NF; i++) {
		split($i, a,":");
		pkgpat = a[1];
		pkgdir = a[2];
		sub(/[\.\/]*/, "", pkgdir);
		if (pkgdir !~ /\//) {
			pkgcat = pkg;
			gsub(/\/.*/, "", pkgcat);
			pkgdir=pkgcat "/" pkgdir;
			if (debug)
				printf("Corrected missing category directory to get \"%s\"\n",
				       pkgdir);
		}
		if (debug){
			printf("package in directory %s %s on:\n",
			       pkg, deptype);
			printf("\tpkgpat = %s\n", pkgpat);
			printf("\tpkgdir = %s\n", pkgdir);
		}


#
# store the package directory in a associative array with the wildcard
# pattern as the index since we will need to be able to look this up later
#
		pat2dir[pkgpat] = pkgdir;

		if (deptype == "depends") {
			depends[pkg] = depends[pkg] " " pkgpat " " ;
			if (debug) {
			  printf("Appending %s to depends[%s] (%s)\n",
				 pkgpat, pkg, depends[pkg]);
			}
		}
		else {
			if (debug) {
			  printf("Appending %s to builddepends[%s] (%s)\n",
				 pkgpat, pkg, builddepends[pkg]);
			}
			builddepends[pkg] = builddepends[pkg] " " pkgpat " " ;
		}
	}

	next;
}

/^maintainer /{
	maintainer[$2] = $3;
	gsub(/@/, " AT ", maintainer[$2]);
	next;
}

/^comment /{
	dir = $2;
	gsub(/^comment[ \t]*/, "");
	tmp = substr($0, length($1) + 1);
	gsub(/^[ \t]*/, "", tmp);
	gsub(/&/, "\\\\\\&amp;", tmp);
	comment[dir] = tmp;
	next;
}

/^homepage /{
	homepage[$2] = $3;
	gsub(/&/, "\\\\&", homepage[$2]);
	next;
}


/^htmlname / {
#
# read lines like:
# htmlname /usr/pkgsrc/archivers/arc <a href=../../archivers/arc/README.html>arc-5.21e</A>
#
#    dir=fulldir2pkgdir($2);
	dir = $2;
	htmlname = $3;
	for (i = 4; i <= NF; i++){
		htmlname = htmlname " " $i;
	}
	# If we are using a name other than README.html, change it
	# here.  This avoids having to process a huge line later which
	# makes lesser awks puke.
	gsub(/README.html/, readme_name, htmlname);
	dir2htmlname[dir] = htmlname;
	if (debug) printf("added dir2htmlname[%s]=%s\n", dir, htmlname);
	next;
}

/^htmloptions / {
	htmloptions = $3;
	origfs = FS;
	FS = "\t";
	for (i = 4; i <= NF; i++){
		htmloptions = htmloptions " " $i;
	}
	FS = origfs;
	options[$2] = htmloptions;
	next;
}

/^index / {
#
# read lines like:
#index /usr/pkgsrc/math/scilab scilab-2.6nb3
# and store the directory name in a associative array where the index
# is the package name and in a associative array that lets us lookup
# name from directory.  We use fuldir2pkgdir to get "math/scilab"
# and drop the /usr/pkgsrc part.
#
#	pkgname2dir[$3] = fulldir2pkgdir($2);
#	pkgdir2name[fulldir2pkgdir($2)] = $3;
	pkgname2dir[$3] = $2;
	pkgdir2name[$2] = $3;
	next;
}

/^license /{
	license[$2] = $3;
	next;
}

/^wildcard /{
	wildcard[$2] = $3;
}

END {
	readme = TMPDIR "/" readme_name;

	printf("Making sure binary package cache file is up to date...\n");
	if ( quiet == "yes" ){
		cmd = sprintf("%s AWK=%s CMP=%s FIND=%s GREP=%s GZIP_CMD=\"%s\" PKG_INFO=\"%s\" PKG_SUFX=%s SED=%s SORT=%s %s/mk/scripts/binpkg-cache %s --packages %s",
		SETENV, AWK, CMP, FIND, GREP, GZIP_CMD, PKG_INFO, PKG_SUFX, SED, SORT, PKGSRCDIR, summary, PACKAGES);
	} else {
		cmd = sprintf("%s AWK=%s CMP=%s FIND=%s GREP=%s GZIP_CMD=\"%s\" PKG_INFO=\"%s\" PKG_SUFX=%s SED=%s SORT=%s %s/mk/scripts/binpkg-cache %s --packages %s --verbose",
		SETENV, AWK, CMP, FIND, GREP, GZIP_CMD, PKG_INFO, PKG_SUFX, SED, SORT, PKGSRCDIR, summary, PACKAGES);
	}
	if (debug) printf("\nExecute:  %s\n",cmd);
	rc = system(cmd);

	if (rc != 0 && rc != 2) {
	  printf("\n**** WARNING ****\n") > "/dev/stderr";
	  printf("Command: %s\nfailed.", cmd) > "/dev/stderr";
	  printf("**** ------- ****\n") > "/dev/stderr";
	  exit(1);
	}

	if (rc == 2) {
	  printf("\n**** WARNING ****\n") > "/dev/stderr";
	  printf("* No binary packages directory found\n") > "/dev/stderr";
	  printf("* List of binary packages will not be generated\n") > "/dev/stderr";
	  printf("**** ------- ****\n") > "/dev/stderr";
	} else {

		printf("Loading binary package cache file...\n");
		load_cache_file( PACKAGES "/.pkgcache" );
       	 if(pkg_count["unknown"] > 0 ) {
			printf("    Loaded %d binary packages with unknown PKGPATH\n", pkg_count["unknown"]);
		}
	}

# extract date for vulnerabilities file
	if (SCAN_VULNERABILITIES == 0)
		vuldate="<li><em>(no vulnerabilities list, update pkg_install)</em></li>";
	else if (SCAN_VULNERABILITIES == 1)
		vuldate="<li><em>(no vulnerabilities list available)</em></li>";

	if (SINGLEPKG != "" ) {
		printf("Only creating README for %s\n",SINGLEPKG);
		for( key in depends ) {
			delete depends[key];
		}
		depends[SINGLEPKG] = "yes";
	}

	printf("Generating README.html files\n");
	pkgcnt = 0;
	if (do_pkg_readme) {
		templatefile = PKGSRCDIR "/templates/README.pkg";
		fatal_check_file(templatefile);
		for (toppkg in depends){
			pkgcnt++;
			pkgdir = PKGSRCDIR "/" toppkg;
			readmenew=pkgdir  "/" readme_name;

			if (debug) printf("Creating %s for %s\n",
					  readme, readmenew);
			if (quiet != "yes") {
				printf(".");
				if ((pkgcnt % 100) == 0) {
					printf("\n%d\n", pkgcnt);
				}
			}
			printf("") > readme;

			run_deps = create_htmldeps(uniq(depends[toppkg]));
			build_deps = create_htmldeps(uniq(builddepends[toppkg]));

			vul = "";

			if (SCAN_VULNERABILITIES == 2) {
				pkgbase = pkgdir2name[toppkg];
				sub("-[^-]*$", "", pkgbase);
				cmd = sprintf("%s audit-history %s", PKG_ADMIN, pkgbase);
				while (cmd | getline vuln_entry) {
					split(vuln_entry, entry, " ");
					status_cmd = sprintf("if %s pmatch '%s' %s; then echo open; else echo fixed; fi",
					    PKG_ADMIN, entry[1], pkgdir2name[toppkg]);
					status_cmd | getline status
					close(status_cmd)
					if (status == "fixed")
						continue
					status = "a " status;
					vul =  sprintf("%s<li>%s <a href=\"%s\">%s</a> vulnerability</li>\n",
					  vul, status, entry[3], entry[2]);
				}
				close(cmd);

				if ( vul == "" ) {
					vul="<em>(no vulnerabilities known)</em>";
				}
			}

			if (debug) {
			  printf("Checking for binary package with lookup_cache( %s)\n",
				 toppkg);
			}
# lookup_cache( wildcard ) will produce HTML for the packages which are found
			lookup_cache( toppkg );

			while((getline < templatefile) > 0){
				gsub(/%%PORT%%/, toppkg);
				gsub(/%%PKG%%/, pkgdir2name[toppkg]);
				gsub(/%%MAINTAINER%%/, maintainer[toppkg]);
				gsub(/%%COMMENT%%/, comment[toppkg]);
				if (homepage[toppkg] == "") {
					gsub(/%%HOMEPAGE%%/, "<em>none stated</em>");
				} else {
					gsub(/%%HOMEPAGE%%/, "<a href=\"" \
					    homepage[toppkg] "\">" homepage[toppkg] "</a>");
				}
				if (license[toppkg] == "") {
					gsub(/%%LICENSE%%/, "<em>none stated</em>");
				} else {
					gsub(/%%LICENSE%%/, "<a href=\"../../licenses/" \
					    license[toppkg] "\">" license[toppkg] "</a>");
				}
				gsub(/%%VULNERABILITIES%%/, ""vul"");
				gsub(/%%VULDATE%%/, ""vuldate"");
				gsub(/%%OPTIONS%%/, escape_re_replacement(""options[toppkg]""));

				gsub(/%%BUILD_DEPENDS%%/, ""build_deps"");
				gsub(/%%RUN_DEPENDS%%/, ""run_deps"");

				line = $0;

				if( line ~/%%BIN_PKGS%%/ ) {
				    gsub(/%%BIN_PKGS%%/, "", line);
				    while((getline < binpkgs_file) > 0) {
				      print >> readme;
				    }
				    close( binpkgs_file );
				}

				descr_file = pkgdir "/DESCR"

				if( line ~/%%DESCR%%/ ) {
				    gsub(/%%DESCR%%/, "", line);
				    while((getline < descr_file ) > 0) {
				      print >> readme;
				    }
				    close( descr_file );
				}

				print line >> readme;
			}
			close(readme);
			close(templatefile);
			cmd = "if [ ! -d " pkgdir " ]; then exit 1 ; fi";
			if (debug) printf("Execute:  %s\n",cmd);
			rc = system(cmd);
			if (rc != 0) {
				printf("\n**** WARNING ****\nPackage directory %s\n",
				       pkgdir) > "/dev/stderr";
				printf("Does not exist.  This is probably ") > "/dev/stderr";
				printf("due to an incorrect DEPENDS line.\n") > "/dev/stderr";
				printf("Try running:  grep %s */*/Makefile\n", fulldir2pkgdir(pkgdir)) > "/dev/stderr";
				printf("or:  grep %s */*/buildlink3.mk\n", fulldir2pkgdir(pkgdir)) > "/dev/stderr";
				printf("to find the problem\n", pkgdir) > "/dev/stderr";
				printf("**** ------- ****\n") > "/dev/stderr";
			} else {
				copy_readme(readmenew, readme);
			}
		}
		printf("\n");
	} # if (do_pkg_readme)
	printf("\n");
	if (SINGLEPKG != "" ) {
		close("/dev/stderr");
		exit 0;
	}
	printf("Generating category readmes\n");
	templatefile = PKGSRCDIR "/templates/README.category";
	fatal_check_file(templatefile);

# string with URLs for all categories (used by the top README.html)
	allcat = "";
# string with URLs for all pkgs (used by the top README-all.html)
	tot_numpkg = 0;
	top_make = PKGSRCDIR"/Makefile";
	while((getline < top_make) > 0){
		if ($0 ~ /^[ \t]*SUBDIR.*=[^\$]*$/) {
			category = $0;
			gsub(/^[ \t]*SUBDIR.*=[ \t]*/, "", category);
			catdir = PKGSRCDIR"/"category;
			readmenew = catdir"/"readme_name;
			if (quiet != "yes") {
				printf("Category = %s\n", category);
			}
			cat_make = catdir"/Makefile";
			pkgs = "";
			numpkg = 0;
			print "" > readme;
			while((getline < cat_make) > 0){
				if ($0 ~ /^[ \t]*SUBDIR.*=[^\$]*$/) {
					pkg = $0;
					gsub(/^[ \t]*SUBDIR.*=[ \t]*/, "",
					     pkg);
					dir = category"/"pkg;
					numpkg++;
					tot_numpkg++;
					if (debug) {
					  printf("\tAdding %s (%s : %s)\n",
						 dir,
						 pkgdir2name[dir],
						 comment[dir]);
					}
					pkgs = sprintf("%s<dt><a href=\"%s/%s\">%s</a></dt><dd>%s</dd>\n",
					    pkgs,
					    pkg, readme_name,
					    pkgdir2name[dir],
					    comment[dir]);
					# Prefix with the package name in a comment for sorting.
					allpkg[tot_numpkg] = sprintf("<!-- %s --><dt><a href=\"%s/%s/%s\">%s</a></dt><dd>%s</dd>\n",
								      pkgdir2name[dir],
								      category, pkg,
								      readme_name,
								      pkgdir2name[dir],
								      comment[dir]);
# we need slightly fewer escapes here since we are not gsub()-ing
# allpkg[] into the output files but just printf()-ing it.
					gsub(/\\&/, "\\&", allpkg[tot_numpkg]);
				} else if ($0 ~ /^[ \t]*COMMENT/) {
					descr = $0;
					gsub(/^[ \t]*COMMENT.*=[ \t]*/, "",
					     descr);
				}
			}
			while ((getline < templatefile) > 0){
				gsub(/%%CATEGORY%%/, category);
				gsub(/%%NUMITEMS%%/, numpkg);
				gsub(/%%DESCR%%/, descr);
				gsub(/%%SUBDIR%%/, ""pkgs"");

				print $0 >> readme;
			}
			close(readme);
			close(templatefile);
			copy_readme(readmenew, readme);

			gsub(/href=\"/, "href=\""category"/", pkgs);
			allcat = sprintf("%s<dt><a href=\"%s/%s\">%s</a></dt><dd>%s</dd>\n",
					 allcat, category, readme_name,
					 category, descr);
			close(cat_make);
		}
	}
	close(top_make);

	printf("Generating toplevel readmes:\n");
	templatefile = PKGSRCDIR "/templates/README.top";
	fatal_check_file(templatefile);
	readmenew = PKGSRCDIR "/"readme_name;
	printf("\t%s\n", readmenew);
	print "" > readme;
	while((getline < templatefile) > 0){
		gsub(/%%DESCR%%/, "");
		gsub(/%%SUBDIR%%/, allcat);
		gsub(/README.html/, readme_name);
		print >> readme;
	}
	close(readme);
	close(templatefile);
	copy_readme(readmenew, readme);

	templatefile = PKGSRCDIR "/templates/README.all";
	fatal_check_file(templatefile);
	readmenew = PKGSRCDIR "/README-all.html";
	printf("\t%s\n", readmenew);
# sort the pkgs
	sfile = TMPDIR"/unsorted";
	spipe = "sort  " sfile;
	i = 1;
	print "" >sfile;
	while(i in allpkg) {
		printf("%s",allpkg[i]) >> sfile;
		i++;
	}
	close(sfile);

	print "" > readme;
	while((getline < templatefile) > 0){
		line = $0;
		if ($0 ~ /%%PKGS%%/) {
			while((spipe | getline) > 0) {
				print  >> readme;
			}
			close(spipe);
		} else {
			gsub(/%%DESCR%%/, "", line);
			gsub(/%%NPKGS%%/, tot_numpkg, line);
			gsub(/README.html/, readme_name, line);
			print line >> readme;
		}
	}
	close(readme);
	close(templatefile);
	copy_readme(readmenew, readme);

	close("/dev/stderr");
	exit 0;
}

function create_htmldeps(dependslist){
	htmldeps = "";
	for( key in dpkgs ) {
		delete dpkgs[key];
	}
	split(dependslist, dpkgs);
	i = 1;
	while(i in dpkgs){
		if (debug) {
		  printf("\tdpkg=%s, pat2dir[%s] = %s\n",
			 dpkgs[i],
			 dpkgs[i],
			 pat2dir[dpkgs[i]]);
		}
		htmldeps = sprintf("%s<a href=\"../../%s/%s\">%s</a>\n",
				 htmldeps,
				 pat2dir[dpkgs[i]],
				 readme_name,
				 pat2dir[dpkgs[i]]);
		i = i + 1;
	}
	if ( i == 1 ) {
	  htmldeps = "<em>(none)</em>";
	}
	return htmldeps;
}

#
# take a string which has special characters like '+' in it and
# escape them.  Also put a space before and after since that's how
# we'll distinguish things like gnome from gnome-libs
#
function reg2str(reg){
	gsub(/\./, "\\.", reg);
	gsub(/\+/, "\\+", reg);
	gsub(/\*/, "\\*", reg);
	gsub(/\?/, "\\?", reg);
	gsub(/\[/, "\\[", reg);
	gsub(/\]/, "\\]", reg);
	reg = " "reg" ";
	return(reg);
}

function escape_re_replacement(s) {
	gsub(/&/, "\\\\\\&", s);
	return s;
}

#
# take a string which has a shell glob pattern and turn it into
# an awk regular expression.
#
function glob2reg(reg){

	# escape some characters which are special in regular expressions
        gsub(/\./, "\\.", reg);
        gsub(/\+/, "\\+", reg);

	# and reformat some others
        gsub(/\*/, ".*", reg);
        gsub(/\?/, ".?", reg);

	# finally, expand {a,b,c} type patterns

        return(reg);
}

#
# accepts a full path to a package directory, like "/usr/pkgsrc/math/scilab"
# and returns just the last 2 directories, like "math/scilab"
#
function fulldir2pkgdir(d, i){
	i = match(d, /\/[^\/]+\/[^\/]+$/);
	return substr(d, i + 1);
}

#
# take the depends lists and uniq them.
#
function uniq(list, deps, i, ulist){

# split out the depends
	split(list, deps);

	i = 1;
	ulist = " ";
	while (i in deps){
#	printf("uniq():  Checking \"%s\"\n", ulist);
#	printf("         for \"%s\"\n", reg2str(deps[i]));
		if (ulist !~reg2str(deps[i])){
			ulist = ulist deps[i]" ";
		}
		i++;
	}
	return(ulist);
}

function fatal_check_file(file, cmd){
	cmd="test -f " file ;
	if (debug) printf("Execute:  %s\n",cmd);
	if (system(cmd) != 0) {
		printf("**** FATAL ****\nRequired file %s does not exist\n",
		       file) > "/dev/stderr";
		printf("**** ------- ****\n") > "/dev/stderr";
		close("/dev/stderr");
		exit(1);
	}
}

# 'new' is the newly created README.html file
# 'old' is the existing (possibly not present) README.html file
#
#  This function copies over the 'new' file if the 'old' one does
#  not exist or if they are different.  In addition, the 'new' one
#  which is a temporary file is removed at the end

function copy_readme(old, new, cmd, rc) {

#	if the README.html file does not exist at all then copy over
#	the one we created

	cmd = "if [ ! -f "old" ]; then cp " new " " old " ; fi";
	if (debug) printf("copy_readme()  execute:  %s\n",cmd);
	rc = system(cmd);
	if (rc != 0) {
		printf("**** WARNING ****\nThe command\n  %s\n", cmd) > "/dev/stderr";
		printf("failed with result code %d\n", rc) > "/dev/stderr";
		printf("**** ------- ****\n") > "/dev/stderr";
	}

#	Compare the existing README.html file to the one we created.  If they are
#	not the same, then copy over the one we created

	cmd = sprintf("%s -s %s %s ; if test $? -ne 0 ; then mv -f %s %s ; fi",
		CMP, new, old, new, old);
	if (debug) printf("copy_readme()  execute:  %s\n",cmd);
	rc = system(cmd);
	if (rc != 0) {
		printf("**** WARNING ****\nThe command\n  %s\n", cmd) > "/dev/stderr";
		printf("failed with result code %d\n", rc) > "/dev/stderr";
		printf("**** ------- ****\n") > "/dev/stderr";
	}

#	If the temp file still exists, then delete it
	cmd = " if [ -f "new" ]; then rm -f "new" ; fi";
	if (debug) printf("copy_readme()  execute:  %s\n",cmd);
	rc = system(cmd);
	if (rc != 0) {
		printf("**** WARNING ****\nThe command\n  %s\n", cmd) > "/dev/stderr";
		printf("failed with result code %d\n", rc) > "/dev/stderr";
		printf("**** ------- ****\n") > "/dev/stderr";
	}

}


function load_cache_file( file, pkgfile, opsys, osver, march, wk, rx ) {
  if ( quiet != "yes" ) printf("    * %s\n", file);
  fatal_check_file( file );

  # read the cache file
  while( getline < file ) {

    # if this line points to another cache file, then recursively
    # load it
    if( $0 ~ /^pkgcache_cachefile/ ) {
      if( debug ) printf("\tFound pkgcache_cachefile line.\n");
      load_cache_file( $2 );
    } else if( $0 ~/^pkgcache_begin /) {
      pkgfile = $2;
      if( debug ) printf("\tStarting %s\n", pkgfile);
      opsys = "unknown";
      osver = "unknown";
      march = "unknown";
      pkgpath = "unknown";
    } else if( $0 ~/^PKGPATH=/ ) {
      pkgpath = $0;
      gsub(/PKGPATH=[ \t]*/, "", pkgpath);
    } else if( $0 ~/^OPSYS=/ ) {
      opsys = $0;
      gsub(/OPSYS=[ \t]*/, "", opsys);
    } else if( $0 ~/^OS_VERSION=/ ) {
      osver = $0;
      gsub(/OS_VERSION=[ \t]*/, "", osver);
    } else if( $0 ~/^MACHINE_ARCH=/ ) {
      march = $0;
      gsub(/MACHINE_ARCH=[ \t]*/, "", march);
    } else if( $0 ~/^pkgcache_end /) {
      if( debug ) printf("\t%s, OPSYS=%s, OS_VERSION=%s, MACHINE_ARCH=%s, PKGPATH=%s\n",
			 pkgfile, opsys, osver, march, pkpath);

      pkg_count[pkgpath] = pkg_count[pkgpath] + 1;

      opsys_list[pkgpath, pkg_count[pkgpath]] = opsys;
      osver_list[pkgpath, pkg_count[pkgpath]] = osver;
      march_list[pkgpath, pkg_count[pkgpath]] = march;
      pkgfile_list[pkgpath, pkg_count[pkgpath]] = pkgfile;
      gsub(/.*\//, "", pkgfile);
      pkgnm_list[pkgpath, pkg_count[pkgpath]] = pkgfile;

    } else {
      # skip this line
    }
  }

  # close the cache file
  close( file );
}

function lookup_cache( d, binpkgs) {
  if( debug ) printf("lookup_cache( %s ):  pkg_count = %d\n",
     d, pkg_count[d]);

  binpkgs_file = TMPDIR "/binpkgs";
  spipe = SORT " > " binpkgs_file;
  for(i=1 ; i<=pkg_count[d]; i=i+1) {
    printf("<tr><td>%s:<td><a href=\"%s/%s\">%s</a><td>(%s %s)\n",
      march_list[d, i], PKG_URL, pkgfile_list[d, i], pkgnm_list[d, i],
      opsys_list[d, i], osver_list[d, i]) | spipe;
  }
  if( pkg_count[d] == 0 ) {
	printf("<tr><td><em>(none)</em></td></tr>\n") | spipe;
  }

  close( spipe );
}


