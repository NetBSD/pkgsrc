 #!/usr/bin/awk -f
# $NetBSD: genreadme.awk,v 1.5 2002/11/16 02:15:15 dmcmahill Exp $
#
# Copyright (c) 2002 The NetBSD Foundation, Inc.
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
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
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
# topdepends[]  : index=pkgdir (math/scilab)
#                 List of explicitly listed depencencies by name.
#                 I.e.  "xless-[0-9]* pvm-3.4.3"
#
# alldepends[]  : index=pkgdir (math/scilab)
#                 Flattened dependency list by name.
#                 
BEGIN {
     do_pkg_readme=1;
# set to 1 to use "README-new.html" as the name
     use_readme_new=0;
     printf("Reading database file\n");
     fflush("/dev/stdout");
 }

#conflicts /usr/pkgsrc/math/scilab 
#depends /usr/pkgsrc/math/scilab xless-[0-9]*:../../x11/xless pvm-3.4.3:../../parallel/pvm3
#

/^(build_)?depends / {
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
    if(pkg in topdepends) {}
    else {topdepends[pkg] = "";}
    if(pkg in topbuilddepends) {}
    else {topbuilddepends[pkg] = "";}

    for(i=3; i<=NF; i++) {
	split($i,a,":");
	pkgpat=a[1];
	pkgdir=a[2];
	sub(/[\.\/]*/,"",pkgdir);
	if(pkgdir !~ /\//) {
	    pkgcat=pkg;
	    gsub(/\/.*/,"",pkgcat);
	    pkgdir=pkgcat "/" pkgdir;
	    if(debug) printf("Corrected missing category directory to get \"%s\"\n",pkgdir);
	}
	if(debug){
	    printf("package in directory %s %s on:\n",pkg,deptype);
	    printf("\tpkgpat = %s\n",pkgpat);
	    printf("\tpkgdir = %s\n",pkgdir);
	}


#
# store the package directory in a associative array with the wildcard
# pattern as the index since we'll need to be able to look this up later
#
	pat2dir[pkgpat]=pkgdir;

	if(deptype == "depends") {
	    topdepends[pkg] = topdepends[pkg] " " pkgpat " " ;
	    if(debug) printf("Appending %s to topdepends[%s] (%s)\n",
			     pkgpat,pkg,topdepends[pkg]);
	}
	else {
	    if(debug) printf("Appending %s to topbuilddepends[%s] (%s)\n",
			     pkgpat,pkg,topbuilddepends[pkg]);
	    topbuilddepends[pkg] = topbuilddepends[pkg] " " pkgpat " " ;
	}
    }
    
    next;
}

/^comment /{
    dir = $2;
    gsub(/^comment[ \t]*/,"");
    tmp=substr($0,length($1)+1);
    gsub(/^[ \t]*/,"",tmp);
    gsub(/&/,"\\\\\\&amp;",tmp);
    comment[dir]=tmp;
    next;
}

/^homepage /{
    homepage[$2] = $3;
    next;
}


/^htmlname / {
#
# read lines like:
# htmlname /usr/pkgsrc/archivers/arc <a href=../../archivers/arc/README.html>arc-5.21e</A>
#
#    dir=fulldir2pkgdir($2);
    dir = $2;
    htmlname=$3;
    for(i=4;i<=NF;i++){
	htmlname=htmlname " " $i;
    }
    dir2htmlname[dir]=htmlname;
    if(debug) printf("added dir2htmlname[%s]=%s\n",dir,htmlname);
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

#
# Now recurse the tree to give a flattened depends list for each pkg
#

END {
    if(use_readme_new) {
	readme_name="README-new.html"
	    }
    else {
	readme_name="README.html";
    }
    readme=TMPDIR "/" readme_name;

    if( dependsfile == "" ) dependsfile="/dev/stdout";
    if( builddependsfile == "" ) builddependsfile="/dev/stdout";

    printf("Flattening dependencies\n");
    fflush("/dev/stdout");
    printf("") > dependsfile;
    for (toppkg in topdepends){
	if(debug) printf("calling find_all_depends(%s)\n",toppkg);
	find_all_depends(toppkg);
	if(debug) printf("%s depends on: %s, topdepends on %s\n",
			 toppkg,alldepends[toppkg],topdepends[toppkg]);
	printf("%s depends on: %s\n",toppkg,alldepends[toppkg]) >> dependsfile;
	flatdepends[toppkg] = alldepends[toppkg];
    }
    close(dependsfile);


# clear out the flattened depends list and repeat for the build depends
    delete alldepends;
    printf("Flattening build dependencies\n");
    fflush("/dev/stdout");
    printf("") > builddependsfile;
    for (toppkg in topbuilddepends){
	find_all_depends(toppkg);
	printf("%s build_depends on: %s\n",
	       toppkg,alldepends[toppkg]) >> builddependsfile;
    }
    close(builddependsfile);


    vfile=DISTDIR "/vulnerabilities";

# extract date for vulnerabilities file
    cmd="ls -l " vfile;
    if((cmd | getline) > 0) {
	vuldate=sprintf("at %s %s %s\n",$6,$7,$8);
# read the vulnerabilities file
	printf("Reading vulnerability file \"%s\"\n which was updated %s\n",
	       vfile,vuldate);
	fflush("/dev/stdout");
	i=1;
	while((getline < vfile) > 0) {
	    if($0 !~ /^\#/) {
		vulpkg[i]=$1;
		vultype[i]=$2;
		vulref[i]=$3;
		i=i+1;
	    }
	}
	printf("   Loaded %d vulnerabilities\n",i-1);
	close(vfile);
	have_vfile=1;
    } else {
	vuldate="<TR><TD><I>(no vulnerabilities list available)</I>";
	printf("No vulnerability file found (%s).\n",vfile);
	have_vfile=0;
    }
    close(cmd);
    fflush("/dev/stdout");

    if(SINGLEPKG != "" ) {
	printf("Only creating README for %s\n",SINGLEPKG);
	delete topdepends;
	topdepends[SINGLEPKG]="yes";
    }

    printf("Generating README.html files\n");
    fflush("/dev/stdout");
    pkgcnt=0;
    if(do_pkg_readme) {
	templatefile=PKGSRCDIR "/templates/README.pkg";
	fatal_check_file(templatefile);
	for (toppkg in topdepends){
	    pkgcnt++;
	    pkgdir=PKGSRCDIR "/" toppkg;
	    readmenew=pkgdir  "/" readme_name;

	    if(debug)printf("Creating %s for %s\n",readme,readmenew);
	    printf(".");
	    if((pkgcnt % 100) == 0) {
		printf("\n%d\n",pkgcnt);
	    }
	    fflush("/dev/stdout");
	    printf("") > readme;
	    htmldeps="";
	    delete dpkgs;
	    split(alldepends[toppkg],dpkgs);
	    i=1;
	    while(i in dpkgs){
		if(debug) printf("\tdpkg=%s, pat2dir[%s] = %s\n",
				 dpkgs[i],dpkgs[i],pat2dir[dpkgs[i]]);
		nm=dpkgs[i];
# we need a zillion escapes here because we need to end up with \\&lt; in 'htmldeps' so that when
# we gsub htmldeps into the output file, we end up with &lt;
		gsub(/&/,"\\\\\\&amp;",nm);
		gsub(/</,"\\\\\\&lt;",nm);
		gsub(/>/,"\\\\\\&gt;",nm);
		htmldeps=sprintf("%s<a href=\"../../%s/%s\">%s</a>\n",
				 htmldeps,pat2dir[dpkgs[i]],readme_name,nm);
		i=i+1;
	    }
	    if(debug) printf("htmldeps = \"%s\"\n",htmldeps);

	    vul="";
	    if(have_vfile) {
		i=1;
		pkgbase=gensub(/-[^-]*$/,"","G",pkgdir2name[toppkg]);
		if(debug) printf("Checking for %s (%s) vulnerabilities\n",toppkg,pkgbase);
		while(i in vulpkg) {
		    nm=vulpkg[i];
		    gsub(/&/,"\\\\\\&amp;",nm);
		    gsub(/</,"\\\\\\&lt;",nm);
		    gsub(/>/,"\\\\\\&gt;",nm);
		    url=vulref[i];
		    gsub(/&/,"\\\\\\&",url);
		    printurl=vulref[i];
		    gsub(/&/,"\\\\\\&amp;",printurl);
		    gsub(/</,"\\\\\\&lt;",printurl);
		    gsub(/>/,"\\\\\\&gt;",printurl);
		    if(vulpkg[i] ~ "^"pkgbase"[-<>=]+[0-9]") {
			vul=sprintf("%s<STRONG><LI> %s has a %s exploit (see <a href=\"%s\">%s</a> for more details)</STRONG>\n", 
				    vul,nm,vultype[i],url,printurl); 
		    }
		    i=i+1;
		}
		if( vul == "" ){
		    vul="<I>(no vulnerabilities known)</I>";
		}
	    }

	    if(MULTIARCH == "no"){
		cmd="ls -1 "PACKAGES "/" PKGREPOSITORYSUBDIR "/" wildcard[toppkg] PKG_SUFX " 2>/dev/null";
		if(debug)printf("Checking for binary package with %s\n",cmd);
		binpkgs="";
		while((cmd | getline) > 0) {
		    pkgfile=$0;
		    gsub(/.*\//,"",pkgfile);
		    pkgnm=pkgfile;
		    gsub(/\.tgz$/,"",pkgnm);
		    binpkgs=sprintf("%s\n<TR><TD>%s:<TD><a href=\"%s/%s\">%s</a><TD>(%s %s)",
				    binpkgs,MACHINE_ARCH,PKG_URL,pkgfile,pkgnm,OPSYS,OS_VERSION);
		}
		close(cmd);}
	    else {
		cmd="ls -1 -d "PACKAGES"/[0-9].*/*/" PKGREPOSITORYSUBDIR "/" wildcard[toppkg] PKG_SUFX " 2>/dev/null";
		oldfs=FS;
		FS="[/]";
		binpkgs="";
		while((cmd | getline) > 0) {
		    release = $(NF-3);
		    arch = $(NF-2);
		    pkg = $NF;
		    pkgnm=pkg;
		    gsub(PKG_SUFX "$","",pkgnm)
			if(debug) printf("%s:%s:%s (%s)\n",release,arch,pkg,pkgnm);
		    binpkgs=sprintf("%s\n<TR><TD>%s:<TD><a href=\"%s/%s/%s/%s/%s\">%s</a><TD>(%s-%s)",
				    binpkgs,arch,PKG_URL,release,arch,PKGREPOSITORYSUBDIR,pkg,pkgnm,OPSYS,release);
		}
		FS=oldfs;
		close(cmd);
	    }

# sort the binary pkgs (XXX would be nice to implement in memory in awk)
	    sfile=TMPDIR "/sorted";
	    spipe="sort > " sfile;
	    printf("%s",binpkgs) | spipe;
	    close(spipe);
	    binpkgs="";
	    while((getline < sfile) > 0) {
		binpkgs=sprintf("%s\n%s",binpkgs,$0);
	    }
	    close(sfile);

	    if(debug) printf("binary packages: \n%s\n\n",binpkgs);

	    while((getline < templatefile) > 0){
		gsub(/%%PORT%%/,toppkg);
		gsub(/%%PKG%%/,pkgdir2name[toppkg]);
		gsub(/%%COMMENT%%/,comment[toppkg]);
		if(homepage[toppkg] == "") {
		    gsub(/%%HOMEPAGE%%/,"");
		} else {
		    gsub(/%%HOMEPAGE%%/,"<p>This package has a home page at <a HREF=\"" homepage[toppkg] "\">" homepage[toppkg] "</a>.</p>");
		}
		if(license[toppkg] == "") {
		    gsub(/%%LICENSE%%/,"");
		} else {
		    gsub(/%%LICENSE%%/,"<p>Please note that this package has a " license[toppkg] " license.</p>");
		}
		gsub(/%%VULNERABILITIES%%/,""vul"");
		gsub(/%%VULDATE%%/,""vuldate"");
		gsub(/%%BUILD_DEPENDS%%/,""htmldeps"");
		gsub(/%%RUN_DEPENDS%%/,""flatdepends[toppkg]"");
		gsub(/%%BIN_PKGS%%/,""binpkgs"");
		gsub(/README.html/,readme_name);
		print >> readme;
	    }
	    close(readme);
	    close(templatefile);
	    cmd="if [ ! -d " pkgdir " ]; then echo "pkgdir" does not exist ; exit 1 ; fi ; if [ ! -f "readmenew" ] || ! cmp -s "readme" "readmenew" ; then mv -f " readme " " readmenew " ; fi";
	    if(debug) printf("Execute:  %s\n",cmd);
	    rc=system(cmd);
	    if(rc != 0) {
		printf("**** WARNING ****\nCould not create %s (rc=%d)\n",readmenew,rc) > "/dev/stderr";
		printf("**** ------- ****\n") > "/dev/stderr";
	    }
	}
	printf("\n");
    } # if(do_pkg_readme)
    printf("\n");
    if(SINGLEPKG != "" ) {
	close("/dev/stderr");
	exit 0;
    }
    printf("Generating category readmes\n");
    templatefile=PKGSRCDIR "/templates/README.category";
    fatal_check_file(templatefile);

# string with URL's for all categories (used by the top README.html)
    allcat="";
# string with URL's for all pkgs (used by the top README-all.html)
    tot_numpkg=0;
    top_make=PKGSRCDIR"/Makefile";
    while((getline < top_make) > 0){
	if($0 ~ /^[ \t]*SUBDIR.*=[^\$]*$/) {
	    category=$0;
	    gsub(/^[ \t]*SUBDIR.*=[ \t]*/,"",category);
	    catdir=PKGSRCDIR"/"category;
	    readmenew=catdir"/"readme_name;
	    printf("Category = %s\n",category);
	    cat_make=catdir"/Makefile";
	    pkgs="";
	    numpkg=0;
	    print "" > readme;
	    while((getline < cat_make) > 0){
		if($0 ~ /^[ \t]*SUBDIR.*=[^\$]*$/) {
		    pkg=$0;
		    gsub(/^[ \t]*SUBDIR.*=[ \t]*/,"",pkg);
		    dir=category"/"pkg;
		    numpkg++;
		    tot_numpkg++;
		    if(debug) printf("\tAdding %s (%s : %s)\n",dir,pkgdir2name[dir],comment[dir]);
		    pkgs=sprintf("%s<TR><TD VALIGN=TOP><a href=\"%s/%s\">%s</a>: %s<TD>\n",
				 pkgs,pkg,readme_name,pkgdir2name[dir],comment[dir]);
		    allpkg[tot_numpkg]=sprintf("<!-- %s (for sorting) --><TR VALIGN=TOP><TD><a href=\"%s/%s/%s\">%s</a>: <TD>(<a href=\"%s/%s\">%s</a>) <td>%s\n",
					       pkgdir2name[dir],category,pkg,readme_name,pkgdir2name[dir],category,readme_name,category,comment[dir]);
# we need slightly fewer escapes here since we're not gsub()-ing allpkg[] into the output files but
# just printf()-ing it.
		    gsub(/\\&/,"\\&",allpkg[tot_numpkg]);
		} else if($0 ~ /^[ \t]*COMMENT/) {
		    descr=$0;
		    gsub(/^[ \t]*COMMENT.*=[ \t]*/,"",descr);
		}
	    }
	    while((getline < templatefile) > 0){
		gsub(/%%CATEGORY%%/,category);
		gsub(/%%NUMITEMS%%/,numpkg);
		gsub(/%%DESCR%%/,descr);
		gsub(/%%SUBDIR%%/,pkgs);
		gsub(/README.html/,readme_name);
		print >> readme;
	    }
	    close(readme);
	    close(templatefile);
	    cmd="if [ ! -f "readmenew" ]; then mv -f "readme " " readmenew " ; fi ; if ! cmp -s "readme" "readmenew" ; then mv -f " readme " " readmenew " ; fi ";
	    if(debug) printf("Execute:  %s\n",cmd);
	    rc=system(cmd);
	    if(rc != 0) {
		printf("**** WARNING ****\nCould not create %s (rc=%d)\n",readmenew,rc) > "/dev/stderr";
		printf("**** ------- ****\n") > "/dev/stderr";
	    }
	    
	    gsub(/href=\"/,"href=\""category"/",pkgs);
	    allcat=sprintf("%s<TR><TD VALIGN=TOP><a href=\"%s/%s\">%s</a>: %s<TD>\n",
			   allcat,category,readme_name,category,descr);
	    close(cat_make);
	}
    }
    close(top_make);

    printf("Generating toplevel readmes:\n");
    templatefile=PKGSRCDIR "/templates/README.top";
    fatal_check_file(templatefile);
    readmenew=PKGSRCDIR "/"readme_name;
    printf("\t%s\n",readmenew);
    print "" > readme;
    while((getline < templatefile) > 0){
	gsub(/%%DESCR%%/,"");
	gsub(/%%SUBDIR%%/,allcat);
	gsub(/README.html/,readme_name);
	print >> readme;
    }
    close(readme);
    close(templatefile);
    cmd="if [ ! -f "readmenew" ]; then mv -f "readme " " readmenew " ; fi ; if ! cmp -s "readme" "readmenew" ; then mv -f " readme " " readmenew " ; fi ";
    if(debug) printf("Execute:  %s\n",cmd);
    rc=system(cmd);
    if(rc != 0) {
	printf("**** WARNING ****\nCould not create %s (rc=%d)\n",readmenew,rc) > "/dev/stderr";
	printf("**** ------- ****\n") > "/dev/stderr";
    }

    templatefile=PKGSRCDIR "/templates/README.all";
    fatal_check_file(templatefile);
    readmenew=PKGSRCDIR "/README-all.html";
    printf("\t%s\n",readmenew);
# sort the pkgs
    sfile=TMPDIR"/unsorted";
    spipe= "sort  " sfile;
    i=1;
    print "" >sfile;
    while(i in allpkg) {
	printf("%s",allpkg[i]) >> sfile;
	i++;
    }
    close(sfile);

    print "" > readme;
    while((getline < templatefile) > 0){
	line=$0;
	if($0 ~ /%%PKGS%%/) {
	    while((spipe | getline) > 0) {
		print  >> readme;
	    }
	    close(spipe);
	} else {
	    gsub(/%%DESCR%%/,"",line);
	    gsub(/%%NPKGS%%/,tot_numpkg,line);
	    gsub(/README.html/,readme_name,line);
	    print line >> readme;
	}
    }
    close(readme);
    close(templatefile);
    cmd="if [ ! -f "readmenew" ]; then mv -f "readme " " readmenew " ; fi ; if ! cmp -s "readme" "readmenew" ; then mv -f " readme " " readmenew " ; fi ";
    if(debug) printf("Execute:  %s\n",cmd);
    rc=system(cmd);
    if(rc != 0) {
	printf("**** WARNING ****\nCould not create %s (rc=%d)\n",readmenew,rc) > "/dev/stderr";
	printf("**** ------- ****\n") > "/dev/stderr";
    }

    close("/dev/stderr");
    exit 0;
} 

function find_all_depends(pkg,pkgreg,i,deps,depdir){
# pkg is the package directory, like math/scilab

#    printf("find_all_depends(%s)\n",pkg);
# if we find the package already has been fully depended
# then return the depends list
    if (pkg in alldepends){
	if(debug) printf("\t%s is allready depended.  Returning %s\n",pkg,alldepends[pkg]);
	return(alldepends[pkg]);
    }

# if this package has no top dependencies, enter an empty flat dependency
# list for it.
    if (topdepends[pkg] ~ "^[ \t]*$") {
	alldepends[pkg] = " ";
	if(debug) printf("\t%s has no depends(%s).  Returning %s\n",pkg,topdepends[pkg],alldepends[pkg]);
	return(alldepends[pkg]);
    }
    
# recursively gather depends that each of the depends has
    pkgreg=reg2str(pkg);
    split(topdepends[pkg],deps);
    i=1;
    alldepends[pkg] = " ";
    while ( i in deps ){

# figure out the directory name associated with the package hame
# in (wild card/dewey) version form
	depdir=pat2dir[deps[i]];
	if(debug) printf("\tadding dependency #%d on \"%s\" (%s)\n",i,deps[i],depdir);
# don't add ourselves to the list (shouldn't happen, but
# we'd like to not get stuck in a loop if one exists)
#	if (" "deps[i]" "!~pkgreg){

# if we don't already have this dependency (deps[i]) listed, then add it.  However, we may
# have already added it because another package we depend on may also have depended on
# deps[i].
	if (alldepends[pkg] !~reg2str(deps[i])){
	    alldepends[pkg] = alldepends[pkg] " " deps[i] " " find_all_depends(depdir);
	} 
	else {
	    if(debug) printf("\t%s is already listed in %s\n",deps[i],alldepends[pkg]);
	}
	
#	}
	i=i+1;
    }
    if(debug) printf("\tcalling uniq() on alldepends[%s] = %s\n",pkg,alldepends[pkg]);
    alldepends[pkg] = uniq(alldepends[pkg]);
    if(debug) printf("\tuniq() output alldepends[%s] = %s\n",pkg,alldepends[pkg]);
    return(alldepends[pkg]);	
}

#
# take a string which has special characters like '+' in it and
# escape them.  Also put a space before and after since that's how
# we'll distinguish things like gnome from gnome-libs
#
function reg2str(reg){
    gsub(/\./,"\\\.",reg);
    gsub(/\+/,"\\\+",reg);
    gsub(/\*/,"\\\*",reg);
    gsub(/\?/,"\\\?",reg);
    gsub(/\[/,"\\\[",reg);
    gsub(/\]/,"\\\]",reg);
    reg = " "reg" ";
    return(reg);
}

#
# accepts a full path to a package directory, like "/usr/pkgsrc/math/scilab"
# and returns just the last 2 directories, like "math/scilab"
#
function fulldir2pkgdir(d){
    d=gensub(/^(.*)(\/)([^\/]*\/[^\/]*)$/,"\\3","g",d);
    return(d);
}

#
# take the depends lists and uniq them.
#
function uniq(list,deps,i,ulist){
    
# split out the depends
    split(list,deps);
    
    i=1;
    ulist = " ";
    while (i in deps){
#	printf("uniq():  Checking \"%s\"\n",ulist);
#	printf("         for \"%s\"\n",reg2str(deps[i]));
	if (ulist !~reg2str(deps[i])){
	    ulist = ulist deps[i]" ";
	}
	i++;
    }
    return(ulist);
}

function fatal_check_file(file,cmd){
	cmd="test -f "file ;
	if(debug) printf("Execute:  %s\n",cmd);
	if(system(cmd) != 0) {
		printf("**** FATAL ****\nRequired file %s does not exist\n",file) > "/dev/stderr";
		printf("**** ------- ****\n") > "/dev/stderr";
		close("/dev/stderr");
		exit(1);
	    }
}

