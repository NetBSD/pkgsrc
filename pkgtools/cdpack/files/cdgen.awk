#!/usr/bin/awk -f
# $NetBSD: cdgen.awk,v 1.1.1.1 2001/04/27 18:16:42 dmcmahill Exp $
#
# Copyright (c) 2001 Dan McMahill, All rights reserved.
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
# ARGV[4] = Depends order file.  Has packages in tsort(1) output format.
# ARGV[5] = CD list.  This script leaves a list of the CD directories in this file
# ARGV[6] = dup flag.  "dup=yes" for package duplication, "dup=no" for no duplication. 
# ARGV[7] = verbose flag.  "verbose=yes" for verbose output
# ARGV[8] = xtra_size.  How many kB are needed per CD for common files

    if (ARGC != 9){
	printf("%s:  wrong number of arguments\n",ARGV[0]);
	usage();
	exit(1);
    }

    prog     = "cdgen.awk";	
    packages = ARGV[1];
    cddir    = ARGV[2];
    deptree  = ARGV[3];
    order    = ARGV[4];
    cdlist   = ARGV[5];
    xtra_size= ARGV[8];

    if (ARGV[6] ~ "dup=yes"){
	dup=1;
    }
    else{
	dup=0;
    }
    if (ARGV[7] ~ "verbose=yes"){
	verbose=1;
    }
    else{
	verbose=0;
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

    cmd="test -f " order ;
    if(system(cmd) != 0){
	printf("%s:  build order file \"%s\" does not exist\n",prog,order);
	usage();
	exit(1);
    }


    now = strftime("%a %b %d %H:%M:%S %Z %Y");
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
    printf("%d packages to go on CD-ROM!\n",npkgs);


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
    printf("Figuring out which packages go on each CD\n");

# maximum kB for binary pkgs per CD.
    maxcd=1024*620;

#
# no package duplication
#
    if (!dup){
	cdn=1;
	pkgn=0;
	cdtot[cdn]=xtra_size;
	cdpkgs[cdn]=0;

	for (n=1; n<=npkgs ; n=n+1){
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
	cdpkgs[cdn] = pkgn;
	printf("cd number %d is partially full (%g Mb)\n",cdn,
	       cdtot[cdn]/1024);
    }

#
# We will duplicate some packages to eliminate inter-CD dependencies.
#
    else{
	cdn=1;
	pkgn=0;
	cdtot[cdn]=xtra_size;
	cdpkgs[cdn]=0;
	n=npkgs;
	while (n > 0){
	    if ( !pkg_done[pkgorder[n]]){
		size_needed = pkgsize[pkgorder[n]];
		deps_needed = 0;
		split(alldepends[pkgorder[n]],pkgdeps);
		for (dep in pkgdeps){
		    if(!cdcontents[cdn":"pkgdeps[dep]]){
			size_needed = size_needed + pkgsize[pkgdeps[dep]];
			deps_needed++;
		    }
		}
		if (cdtot[cdn] + size_needed < maxcd){
		    cdcontents[cdn":"pkgorder[n]] = 1;
		    pkg_done[pkgorder[n]] = 1;
		    for (dep in pkgdeps){
			cdcontents[cdn":"pkgdeps[dep]] = 1;
			pkg_done[pkgdeps[dep]] = 1;
		    }
		    cdtot[cdn] = cdtot[cdn] + size_needed;
		    n--;
		    pkgn = pkgn + 1 + deps_needed;
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
		n--;
	    }

	}
	cdpkgs[cdn] = pkgn;
	printf("cd number %d is partially full (%g Mb)\n",cdn,
	       cdtot[cdn]/1024);
    }

# remember how many cd's there are
    ncd=cdn;

# print some stats
    if (dup){
	tot_cdpkgs=0;
	for (cdn=1; cdn<=ncd; cdn=cdn+1){
	    tot_cdpkgs = tot_cdpkgs + cdpkgs[cdn];
	}
	printf("CD images with package duplication resulted in %d packages total\n",tot_cdpkgs);
	printf("This is an increase of %d over the base %d packages\n",tot_cdpkgs-npkgs,npkgs);
    }
	
#
# Next, create a subdirectory for each CD and populate the directory
# with links to the actual binary pkgs
#
    printf("Creating subdirectories for each CD and populating it with links\n");
    printf("to the binary packages and other required files.\n");
    for (cdn=1; cdn<=ncd; cdn=cdn+1){
	printf("----------- CD #%d ----------\n",cdn);
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

    now = strftime("%a %b %d %H:%M:%S %Z %Y");
    printf("%s finished on %28s\n",prog,now);

    printf("\n");

    exit 0
	} 

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
