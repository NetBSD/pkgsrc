#!/bin/sh
# $NetBSD: cdpack.sh,v 1.1.1.1 2001/04/27 18:16:42 dmcmahill Exp $
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

# $0 = program name
# $2 = packages directory (/usr/pkgsrc/packages/All)
# $3 = output directory

prog=cdpack	
progver=@progver@

TMPDIR=${TMPDIR:-/tmp}
TMP=${TMPDIR}/${prog}.$$

depf=$TMP/depf
depf2=$TMP/depf2
deptree=$TMP/deptree
order=$TMP/order
cdlist=$TMP/cdlist
indexf=$TMP/indexf
readme=$TMP/readme
warnings=$TMP/warnings

rm -fr $TMP
mkdir $TMP 

usage(){
	echo "$prog - generates ISO9660 images for a multi-cd binary package collection"
	echo "Usage:      $prog packages_directory cdimage_directory"
	echo "Example:    $prog /usr/pkgsrc/packages/netbsd-1.5/alpha/All  /images/netbsd-1.5/alpha"
}

clean_and_exit(){
	rm -fr $TMP
	exit 1
}

DUP=yes
VERBOSE=no
VERSION=no
USE_XTRA=no

while
    test -n "$1"
do
    case "$1"
    in
	# do not duplicate packages to avoid inter-CD dependencies
	-n) DUP=no
	    shift
	    ;;
	    
	# be verbose 
	-v) VERBOSE=yes
	    shift
	    ;;

	# display version
	-V) VERSION=yes
	    shift
	    ;;

	# extra directory to go on each CD.
	-x) extra=$2
	    USE_XTRA=yes
	    shift 2
	    ;;

	-*) echo "$prog:  ERROR:  $s is not a valid option"
	    usage
	    clean_and_exit
	    ;;

	*)  ARGS="$ARGS $1"
	    shift
	    ;;
    esac
done

if [ $VERSION = "yes" ]; then
    echo "$prog-$progver"
    rm -fr $TMP
    exit 0
fi

set -- $ARGS

if [ $# -ne 2 ]; then
	echo "$prog:  wrong number of arguments"
	usage
	clean_and_exit
fi

packages=$1
cddir=$2

if [ $VERBOSE = "yes" ]; then
    echo "Verbose output is on"
fi

#
# Make sure all required directories and files exist
#

if [ ! -d $packages ]; then
	echo "$prog:  packages directory \"$packages\" does not exist"
	usage
	clean_and_exit
fi

if [ ! -d $cddir ]; then
	echo "$prog:  cd image directory \"$cddir\" does not exist"
	usage
	clean_and_exit
fi

if [ "$USE_XTRA" = "yes" -a ! -d $extra ]; then
	echo "$prog:  extra directory \"$extra\" specified with -x does not exist"
	usage
	clean_and_exit
fi

if [ "$USE_XTRA" = "yes" ]; then
	case $extra in
		/*) # do nothing, its an absolute path
			;;
		*)  extra=`pwd`/$extra
			;;
	esac
	XTRA_SIZE=`du -sk $extra | awk '{print $1}'`
	if [ "$VERBOSE" = "yes" ]; then
		echo "Extra directory full path name is \"$extra\".  It contains $XTRA_SIZE kB."
	fi
else
    XTRA_SIZE=0
fi

echo " "
echo "$prog starting: `date`" 
echo " "

#
# go through all the binary packages and extract their run depends and
# also any package conflicts.
#
# $deptree = this file contains a tsort(1) run depends tree using
#            binary package names.
#

npkgs=0
echo "Extracting all dependency information for the binary packages..."
for pkg in $packages/*
do
	if [ -f $pkg ]; then
		# extract the packge name
		pkgname=`basename $pkg .tgz`

		# extract the packing list
		cat $pkg | (cd $TMP; tar --fast-read -xzf - +CONTENTS)

		# extract the depends
		deps=`awk '/^@pkgdep/ {printf("%s ",$2)}' $TMP/+CONTENTS`

		# extract any conflicts
		cfls=`awk '/^@pkgcfl/ {printf("%s ",$2)}' $TMP/+CONTENTS`

		rm $TMP/+CONTENTS
		
		# store the results
		echo "$pkgname | $deps | $cfls" >> $depf

		# also process all of the listed depends with 
		# 'pkg_admin lsbest' to handle glob patterns
		bestdeps=" "
		listed=no
		if [ ! -z "$deps" ]; then
		    for dep in $deps
		    do
			best=`/usr/sbin/pkg_admin lsbest "${packages}/${dep}"`
			if [ ! -z "$best" ]; then
			    best=`basename $best .tgz`
			    bestdeps=$bestdeps" "$best
			    echo "$best	$pkgname" >> $deptree
			    listed=yes
			else
			    echo "WARNING: $pkgname depends on \"$dep\" which was not found"
			    echo "WARNING: $pkgname depends on \"$dep\" which was not found" >> $warnings
			fi
		    done
		fi
		if [ "$listed" = "no" ]; then
		    # make sure we add ourselves to the tree if we have no depends or if the 
		    # depends were not found
		    echo "$pkgname	$pkgname" >> $deptree
		fi

		echo "$pkgname | $bestdeps | $cfls" >> $depf2

		npkgs=$(($npkgs + 1))
	else
		# Don't bomb out on 1 package
		echo "$prog: warning: $pkg not readable"
	fi
done

echo " "
echo "Finished extracting dependencies and conflicts for $npkgs binary packages"
echo " "

#
# sort the packages in dependency order
#
mv $deptree ${deptree}.bak
sort -u ${deptree}.bak > ${deptree}
tsort $deptree > $order

#
# Run the awk program which figures out which packages go on which CD.
# This program also creates subdirectories and populates them with
# links to the actual binary pacakges.
#
#    packages = ARGV[1];
#    cddir    = ARGV[2];
#    deptree  = ARGV[3];
#    order    = ARGV[4];
#    cdlist   = ARGV[5];
#
if [ "$VERBOSE" = "yes" ]; then
	echo "awk -f cdgen.awk $packages $cddir $deptree $order $cdlist dup=$DUP"
fi
awk -f @prefix@/libexec/cdgen.awk $packages $cddir $deptree $order $cdlist dup=$DUP verbose=$VERBOSE $XTRA_SIZE

if [ $? -ne 0 ]; then
    echo "$prog:  ERROR:  cdgen.awk has failed"
    clean_and_exit
fi

#
# Generate a README
#
cat <<EOF > $readme
This CD-ROM collection contains NetBSD binary packages.  For
information on the NetBSD package collection, please visit
http://www.netbsd.org/Documentation/software/packages.html.

For more information about the NetBSD project, visit the
project homepage at http://www.netbsd.org

EOF

if [ "$DUP" = "yes" ]; then
cat <<EOF >> $readme
The packages on this CD have been arranged to eliminate all
inter-CD dependencies.  In other words, each package on this
CD should have all of its dependencies (if they are allowed
to be provided on CD) present on the same CD.

EOF
else

cat <<EOF >> $readme
The packages on this CD have been arranged such that for a
given package on CD number n, all of the other required
packages are on CD number 1 through n.  This allows the 
user to make a single pass through the CD set when installing
a collection of packages.

EOF
fi

cat <<EOF >> $readme

This README, along with the CD layout was created using the
cdpack program which is available as part of the NetBSD
packages collection at 
ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/pkgtools/cdpack
.

EOF

# 
# Generate an index file which lists the contents of each CD.
#

echo "Creating CD Index File"

for cdname in `cat $cdlist`
do
    for pkg in ${cddir}/${cdname}/packages/All/*
    do
	echo "`basename $pkg`  $cdname" >> $indexf
    done
done
mv $indexf ${indexf}.tmp
sort ${indexf}.tmp > $indexf

#
# Populate the cd's with the index file and readme
# actually copy these over since the originals will
# be deleted from their temporary directories
#
ncds=0
for cdname in `cat $cdlist`
do
    (cd ${cddir}/${cdname} && cp $indexf .index)
    (cd ${cddir}/${cdname} && cp $readme README.txt)

    if [ $USE_XTRA = "yes" ]; then
	for f in $extra/*
	do
	    (cd ${cddir}/${cdname} && ln -sf $f)
	done
    fi

    ncds=$(($ncds + 1))
done

#
# Create the ISO Images
#
volid=PackagesCD
#mkisofs_flags="-f -l -r -J -L -volset-size $ncds -V $volid "
mkisofs_flags="-f -l -r -J -L "

echo "Creating the ISO images"
cdn=1
for cdname in `cat $cdlist`
do
    echo "----------- $cdname ----------"
    #mkisofs_flags2=" -volset-ID $cdname -volset-seqno $cdn "
    mkisofs_flags2=" -V ${volid}$cdn "
    echo "(cd ${cddir} && mkisofs $mkisofs_flags $mkisofs_flags2 -o ${cdname}.iso $cdname)"
    ( cd ${cddir} && mkisofs $mkisofs_flags $mkisofs_flags2 -o ${cdname}.iso $cdname )
    if [ $? != 0 ]; then
	echo "mkisofs failed"
	clean_and_exit
    fi
    cdn=$(($cdn + 1))
done

echo "ISO Images are available in $cddir"

if [ -f $warnings ]; then
	echo "There were warnings generated:"
	cat $warnings
fi

echo " "
echo "$prog finished: `date`" 
echo " "

rm -fr $TMP

exit 0

