#!/usr/bin/awk -f
# $NetBSD: cdgen.awk,v 1.5 2005/01/09 15:33:09 dmcmahill Exp $
#
# Copyright (c) 2001, 2002, 2003 Dan McMahill, All rights reserved.
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
#	This product includes software developed by Dan McMahill
# 4. The name of the author may not be used to endorse or promote
#    products derived from this software without specific prior written
#    permission.
#
# THIS SOFTWARE IS PROVIDED BY DAN MCMAHILL
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

BEGIN {

# ARGV[0] = program name
# ARGV[1] = packages directory (/usr/pkgsrc/packages/All)
# ARGV[2] = output directory
# ARGV[3] = Depends tree file.  Has packages in tsort(1) input format.
# ARGV[4] = Exclude file.  Packages listed here are excluded.
# ARGV[5] = Depends order file.  Has packages in tsort(1) output format.
# ARGV[6] = CD list.  This script leaves a list of the CD directories in this file
# ARGV[7] = dup flag.  "dup=yes" for package duplication, "dup=no" for no duplication. 
# ARGV[8] = verbose flag.  "verbose=yes" for verbose output
# ARGV[9] = xtra_size.  How many kB are needed per CD for common files

    reqnum = 12;
    if (ARGC != reqnum){
	printf("cdgen.awk:  wrong number of arguments (got %d, wanted %d)\n", ARGC, reqnum);
	usage();
	exit(1);
    }

    prog     = "cdgen.awk";	
    packages = ARGV[1];
    cddir    = ARGV[2];
    deptree  = ARGV[3];
    exclude  = ARGV[4];
    order    = ARGV[5];
    cdlist   = ARGV[6];
    xtra_size= ARGV[10];
    other_size= ARGV[11];

    if (ARGV[7] ~ "dup=yes"){
	dup=1;
    }
    else{
	dup=0;
    }
    if (ARGV[8] ~ "verbose=yes"){
	verbose=1;
    }
    if (ARGV[9] ~ "dvd=yes"){
	dvd=1;
    }
    else{
	dvd=0;
    }

#
# Make sure all required directories and files exist
#
    cmd="test -d " packages ;
    if(system(cmd) != 0){
	printf("%s:  packages directory \"%s\" does not exist\n",prog,packages);
	usage();
	exit(1);
    }

    cmd="test -d " cddir ;
    if(system(cmd) != 0){
	printf("%s:  cd image directory \"%s\" does not exist\n",prog,cddir);
	usage();
	exit(1);
    }

    cmd="test -f " deptree ;
    if(system(cmd) != 0){
	printf("%s:  dependstree file \"%s\" does not exist\n",prog,deptree);
	usage();
	exit(1);
    }
    
    cmd="test -f " exclude ;
    if(system(cmd) != 0){
	printf("%s:  exclude file \"%s\" does not exist\n",prog,exclude);
	usage();
	exit(1);
    }
    
    cmd="test -f " order ;
    if(system(cmd) != 0){
	printf("%s:  build order file \"%s\" does not exist\n",prog,order);
	usage();
	exit(1);
    }
    
    
    "date" | getline now;
    printf("%s starting %28s\n",prog,now);
    
#
# Read in the build order.  This gives the list of all possible 
# packages (note that some may actually not be available as binary
# packages).  The order is such that a package earlier in the list
# will never depend on a package lower on the list. 
# 

    printf("Reading the depends order from \"%s\".\n",order);
    n=1;
    while(getline < order > 0){
	pkgorder[n] = $1;
	n++;
    }
    close(order);
    npkgs = n-1;
    printf("%d packages to go on CD-ROM/DVD!\n",npkgs);

#
# Read in the list of excluded packages
#
    printf("Reading list of packages to be excluded\n");
    while(getline < exclude > 0){
	excludes[$1] = 1 ;
    }
    close(exclude);

#
# Read in the depends tree and flatten it.
#
    printf("Reading depends tree\n");
    while(getline < deptree > 0){
	if ($2 in topdepends)
	    topdepends[$2] = topdepends[$2] " " $1 " " ;
	else
	    topdepends[$2] = " " $1 " " ;
    }
    close(deptree);

# Now recurse the tree to give a flattened depends list for each pkg
    printf("Flattening depends tree\n");
    for (toppkg in topdepends){
	find_all_depends(toppkg);
    }


#
# Next get the sizes of each of the binary pacakges if they
# exist.  For those which don't exist, make a note of that.
# getsize() returns size in kB if the file exists, 0 otherwise.
#
    printf("Loading binary package sizes\n");
    nonzero=0;
    totsize=0;
    for (n in pkgorder){
	pkgsize[pkgorder[n]] = getsize(pkgorder[n]);
	if(pkgsize[pkgorder[n]] > 0){
	    nonzero++;
	}
	else{
	    printf("WARNING:  binary package \"%s\" has zero size\n",pkgorder[n]);
	}
	totsize = totsize + pkgsize[pkgorder[n]];
    }
    printf("%d binary packages are available (%g Mb)!\n",nonzero,totsize/1024);

#
# Now we need to figure out which binary packages go on each
# CD.  The way we'll do this is start taking packages in the order
# specified by 'pkgorder' until the first CD is full, then move
# to the second, etc.  This way, we never have to reinsert a CD
# while installing pkgs.
#
    printf("Figuring out which packages go on each CD/DVD\n");

# maximum kB for binary pkgs per CD.
    if( dvd ) 
	maxcd = 1024 * 4300;
    else
	maxcd = 1024 * 620;

    if( verbose ) printf("Maximum image size = %g Mb\n", maxcd/1024);
#
# no package duplication
#
    if (!dup){
	cdn=1;
	pkgn=0;
	cdtot[cdn]=xtra_size;
	cdpkgs[cdn]=0;
	
	for (n=1; n<=npkgs ; n=n+1){
	    if (verbose) printf("Processing: %s\n",pkgorder[n]);
	    if (pkgorder[n] in excludes) {
		if (verbose) printf("Skipping excluded package: %s\n",pkgorder[n]);
	    }
	    else {
# only process the package if it exists.
		if (pkgsize[pkgorder[n]] > 0){
		    if (cdtot[cdn] < (maxcd-pkgsize[pkgorder[n]]) ){
			cdtot[cdn] = cdtot[cdn] +pkgsize[pkgorder[n]];
			cdcontents[cdn":"pkgorder[n]] = 1;
			pkgn = pkgn + 1;
		    }
		    else{
# the CD is full
			printf("cd number %d is full (%g Mb)\n",cdn,
			       cdtot[cdn]/1024);
			cdpkgs[cdn] = pkgn;
# increment the CD counter
			cdn = cdn + 1;
			pkgn = 1;
			cdtot[cdn] = xtra_size + pkgsize[pkgorder[n]];
			cdcontents[cdn":"pkgorder[n]] = 1;
		    }
		}
	    }
	}
	cdpkgs[cdn] = pkgn;
	
# see if the extra files will fit on the last CD
	if ( (cdtot[cdn] + other_size) < maxcd ){
	    printf("cd number %d is partially full (%g Mb)\n",cdn,
		   cdtot[cdn]/1024);
	}
	else{
	    printf("cd number %d is full (%g Mb)\n",cdn,
		   cdtot[cdn]/1024);
	    cdn = cdn + 1;
	    cdtot[cdn] = other_size;
	    cdpkgs[cdn] = 0;
	    printf("cd number %d is partially full (%g Mb)\n",cdn,
		   cdtot[cdn]/1024);
	}
	
    }
    
#
# We will duplicate some packages to eliminate inter-CD dependencies.
#
    else{
	cdn=1;
	pkgn=0;
# initialize the size count for the current CD with the extras that we
# are putting on all CD's
	cdtot[cdn]=xtra_size;
	cdpkgs[cdn]=0;
	n=npkgs;
	while (n > 0){
	    if (verbose) printf("Begin processing %s\n",pkgorder[n]);
	    if ( !pkg_done[pkgorder[n]]){
		size_needed = pkgsize[pkgorder[n]];
		deps_needed = 0;
		split(alldepends[pkgorder[n]],pkgdeps);
		for (dep in pkgdeps){
		    if (verbose) printf("   Examining dependency: %s\n",pkgdeps[dep]);
		    if (pkgdeps[dep] in excludes) {
			if (verbose) printf("   Skipping excluded dependency in count: %s\n",pkgdeps[dep]);
		    }
		    else {
			if(!cdcontents[cdn":"pkgdeps[dep]]){
			    size_needed = size_needed + pkgsize[pkgdeps[dep]];
			    deps_needed++;
			}
		    }
		}
		if (cdtot[cdn] + size_needed < maxcd){
		    if (verbose) printf("   Processing %s\n",pkgorder[n]);
		    if (pkgorder[n] in excludes) {
			if (verbose) printf("   Skipping excluded package in packing: %s\n",pkgorder[n]);
		    }
		    else {
			cdcontents[cdn":"pkgorder[n]] = 1;
		    }
		    pkg_done[pkgorder[n]] = 1;
		    if (verbose) printf("   Marked %s as processed\n",pkgorder[n]);
		    for (dep in pkgdeps){
			if (pkgdeps[dep] in excludes) {
			    if (verbose) printf("   Skipping excluded dependency in packing: %s\n",pkgdeps[dep]);
			}
			else {
			    cdcontents[cdn":"pkgdeps[dep]] = 1;
			    pkg_done[pkgdeps[dep]] = 1;
			    if (verbose) printf("   Marked dependency pkg %s as processed\n",pkgdeps[dep]);
			}
		    }
		    cdtot[cdn] = cdtot[cdn] + size_needed;
		    if (pkgorder[n] in excludes) {
# don't include this one in the count if its excluded
			if (verbose) printf("   Added  %d dependencies to the image\n",deps_needed);
			pkgn = pkgn + deps_needed;
		    }
		    else {
			if (verbose) printf("   Added %s plus %d dependencies to the image\n",pkgorder[n],deps_needed);
			pkgn = pkgn + 1 + deps_needed;
		    }
		    n--;
		}
		else{
# the CD is full
		    printf("cd number %d is full (%g Mb)\n",cdn,
			   cdtot[cdn]/1024);
		    cdpkgs[cdn] = pkgn;
		    cdn++;
		    cdtot[cdn] = xtra_size;
		    pkgn = 0;
		}
	    }
	    else{
# we've already done this pkg
		if (verbose) printf("   %s has already been processed\n",pkgorder[n]);
		n--;
	    }
	    
	}
	cdpkgs[cdn] = pkgn;

# see if the extra files will fit on the last CD
	if ( (cdtot[cdn] + other_size) < maxcd ){
	    printf("cd number %d is partially full (%g Mb)\n",cdn,
		   cdtot[cdn]/1024);
	}
	else{
	    printf("cd number %d is full (%g Mb)\n",cdn,
		   cdtot[cdn]/1024);
	    cdn = cdn + 1;
	    cdtot[cdn] = other_size;
	    cdpkgs[cdn] = 0;
	    printf("cd number %d is partially full (%g Mb)\n",cdn,
		   cdtot[cdn]/1024);
	}
    }

# remember how many cd's there are
    ncd=cdn;

# print some stats
    tot_ex=0;
    for (ex in excludes){
	tot_ex++;
    }
    if (dup){
	tot_cdpkgs=0;
	for (cdn=1; cdn<=ncd; cdn=cdn+1){
	    tot_cdpkgs = tot_cdpkgs + cdpkgs[cdn];
	}
	printf("CD/DVD images with package duplication resulted in %d packages total\n",tot_cdpkgs);
	printf("This is an increase of %d over the base %d packages\n",tot_cdpkgs-(npkgs-tot_ex),npkgs-tot_ex);
    }
	
    printf("%d packages out of %d have been excluded due to redistribution restrictions\n",tot_ex,npkgs);
#
# Next, create a subdirectory for each CD and populate the directory
# with links to the actual binary pkgs
#
    printf("Creating subdirectories for each CD/DVD and populating it with links\n");
    printf("to the binary packages and other required files.\n");
    for (cdn=1; cdn<=ncd; cdn=cdn+1){
	printf("----------- CD/DVD #%d ----------\n",cdn);
	printf("      %3d binary packages\n",cdpkgs[cdn]);
	outdir=cddir "/cd" cdn "/packages/All";
	cmd="test -d " outdir;
	if(system(cmd) == 0){
	    printf("%10s:  output dir \"%s\" already exists.\n",prog,outdir);
	    printf("%10s   please remove it.\n","");
	    exit(1);
	}
	
# create output directory
	cmd = "mkdir -p " outdir;
	do_system(cmd);
	
# populate it with the symlinks to the binary packages
	for (n=1; n<=npkgs; n++){
	    if (cdcontents[cdn":"pkgorder[n]]){
		cmd = "cd " outdir " && ln -s " packages "/" ;
		cmd = cmd pkgorder[n] ".tgz";
		do_system(cmd);
	    }
	}

# add it to the cd list
	printf("cd%d\n",cdn) > cdlist ;
	
    }

    close(cdlist);

    "date" | getline now;
    printf("%s finished on %28s\n",prog,now);

    printf("\n");

    exit 0
	} # BEGIN

function getsize(name,cmd,sz){

    cmd="test -f " packages "/" name ".tgz";
    if(system(cmd) == 0){
	cmd="du -k " packages "/" name ".tgz";
	cmd | getline ;
	close(cmd);
	sz=$1;
    }
    else{
	sz=0;
    }

    return(sz);	
}

function do_system(cmd,rv){
    rv = system(cmd);
    if (rv != 0){
	printf("Error:  system(\"%s\") returned %d\n",cmd,rv);
	exit(1);
    }
    return(0);
}

#
# show usage
#
function usage(){
    printf("\nUsage:\n\n");
    printf("%10s -- Create directories for building binary package ISO images\n",
	   prog,prog);
    printf("%10s    packages images dependstree order cdlist\n","");
    printf("\n");
    printf("\n");

}


function find_all_depends(pkg,pkgreg,i,deps){
# if we find the package already has been fully depended
# then return the depends list
    if (pkg in alldepends){
#	printf("\t%s is already depended.\n",pkg);
	return(alldepends[pkg]);	
    }

# if we find the package listed in its own depends list, then
# return an empty list if we're going down the depends tree.
# When a package lists itself in the depends tree file, it simply
# is a place holder and means the package has no depends.  However
# other packages may still depend upon it, so we need to keep looking.
    if ( topdepends[pkg]~reg2str(pkg) ){
#	printf("\t%s depends on its self.\n",pkg);
	alldepends[pkg] = " ";
	return(alldepends[pkg]);	
    }

# otherwise recursively gather depends that each of the depends
# has
    pkgreg=reg2str(pkg);
    split(topdepends[pkg],deps);
    i=1;
    alldepends[pkg] = " ";
    while ( i in deps ){
# don't add ourselves to the list (a possibility when going up the tree)
	if (" "deps[i]" "!~pkgreg){
	    alldepends[pkg] = alldepends[pkg] " " deps[i] " " find_all_depends(deps[i]);
	}
	i=i+1;
    }
    alldepends[pkg] = uniq(alldepends[pkg]);
    return(alldepends[pkg]);	
}

#
# take a string which has special characters like '+' in it and
# escape them.  Also put a space before and after since that's how
# we'll distinguish things like gnome from gnome-libs
#
function reg2str(reg){
    gsub(/\+/,"\\\+",reg);
    gsub(/\./,"\\\.",reg);
    reg = " "reg" ";
    return(reg);
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
	if (ulist !~reg2str(deps[i])){
	    ulist = ulist deps[i]" ";
	}
	i++;
    }
    return(ulist);
}
