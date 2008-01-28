#!/bin/sh
# $NetBSD: cdpack.sh,v 1.12 2008/01/28 23:03:48 dmcmahill Exp $
#
# Copyright (c) 2001, 2002, 2003, 2005 Dan McMahill, All rights reserved.
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
AWK=${AWK:-@AWK@}
EXPR="@EXPR@"
SORT="@SORT@"
TSORT="@TSORT@"

depf=$TMP/depf
depf2=$TMP/depf2
deptree=$TMP/deptree
exclude=$TMP/exclude
order=$TMP/order
cdlist=$TMP/cdlist
indexf=$TMP/indexf
readme=$TMP/readme
warnings=$TMP/warnings
restricted=$TMP/restricted

rm -fr $TMP
mkdir $TMP 
touch $exclude

usage(){
	echo " "
	echo "$prog - generates ISO9660 images for a multi-cd binary package collection"
	echo "Usage:      $prog [-ac | -ec] [-af | -ef] [-dvd] [-h|--help] [-l logfile] [-dnRvV]"
	echo "            [-o opsys] [-m machine] [-r release]"
	echo "            [-x dir] [-X dir] packages_directory cdimage_directory"
	echo "Example:    $prog /usr/pkgsrc/packages/All  /images/netbsd-1.5/alpha"
	echo "Please refer to the manual page for complete documentation."
	echo " "
}

clean_and_exit(){
	if [ "x$DEBUG" = "xno" ]; then
	    rm -fr $TMP
        else
	    echo "Debugging output left in $TMP"
	fi
	exit 1
}

# return the full path name from a path which may
# be a full path name or a relative path name
fullpath(){
    local x
    x=$1
    case $x in
	/*) # do nothing, its an absolute path
	    ;;
	 *)  x=`pwd`/$x
	    ;;
    esac
    echo $x
}

ADD_README=no
ARCH=`uname -m`
DEBUG=no
DUP=yes
OS=`uname -s`
RELEASE=`uname -r`
VERBOSE=no
VERSION=no
USE_XTRA=no
USE_OTHERS=no
mkisofslog=/dev/null

ALLOW_NO_BIN_ON_CDROM=no
ALLOW_NO_BIN_ON_FTP=yes
DVD=no

while
    test -n "$1"
do
    case "$1"
    in
	# allow NO_BIN_ON_CDROM packages
	-ac) ALLOW_NO_BIN_ON_CDROM=yes
	    shift
	    ;;

	# allow NO_BIN_ON_FTP packages
	-af) ALLOW_NO_BIN_ON_FTP=yes
	    shift
	    ;;

	# enable debugging
	-d) DEBUG=yes
	    shift
	    ;;

	# make a DVD sized image
	-dvd) DVD=yes
	    shift
	    ;;

	# exclude NO_BIN_ON_CDROM packages
	-ec) ALLOW_NO_BIN_ON_CDROM=no
	    shift
	    ;;

	# exclude NO_BIN_ON_FTP packages
	-ef) ALLOW_NO_BIN_ON_FTP=no
	    shift
	    ;;

	# help
	-h|--help) usage
	    exit 0
	    ;;

	# log file for the output of mkisofs -v -v
	-l) mkisofslog=$2
	    shift 2
	    ;;

	# target machine architecture for these packages
	-m) ARCH=$2
	    shift 2
	    ;;

	# do not duplicate packages to avoid inter-CD dependencies
	-n) DUP=no
	    shift
	    ;;
	   
	# target os for these packages
	-o) OS=$2
	    shift 2
	    ;;

	# target os version for these packages
	-r) RELEASE=$2
	    shift 2
	    ;;

	# automatically generate a README.txt file for each CD-ROM
	-R) ADD_README=yes
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

	# extra directory to go on only 1 CD (pkgsrc.tar.gz for example)
	-X) others=$2
	    USE_OTHERS=yes
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

if [ "$VERBOSE" = "yes" ]; then
    echo "Verbose output is on"

    if [ "$ALLOW_NO_BIN_ON_CDROM" = "yes" ]; then
	echo "NO_BIN_ON_CDROM Packages will be included in the images"
    else
	echo "NO_BIN_ON_CDROM Packages will be excluded in the images"
    fi

    if [ "$ALLOW_NO_BIN_ON_FTP" = "yes" ]; then
	echo "NO_BIN_ON_FTP Packages will be included in the images"
    else
	echo "NO_BIN_ON_FTP Packages will be excluded in the images"
    fi

    if [ "$DVD" = "yes" ]; then
	echo "A DVD sized image will be created"
    else
	echo "A CD-ROM sized image will be created"
    fi
fi

#
# Make sure all required directories and files exist
#

if [ ! -d $packages ]; then
	echo "$prog:  packages directory \"$packages\" does not exist"
	usage
	clean_and_exit
else
    packages=`fullpath $packages`
fi

if [ ! -d $cddir ]; then
	echo "$prog:  cd image directory \"$cddir\" does not exist"
	usage
	clean_and_exit
else
    cddir=`fullpath $cddir`
fi

if [ "$USE_XTRA" = "yes" -a ! -d $extra ]; then
	echo "$prog:  extra directory \"$extra\" specified with -x does not exist"
	usage
	clean_and_exit
fi

if [ "$USE_XTRA" = "yes" ]; then
    extra=`fullpath $extra`
    XTRA_SIZE=`du -sk $extra | ${AWK} '{print $1}'`
    if [ "$VERBOSE" = "yes" ]; then
	echo "Extra directory full path name is \"$extra\".  It contains $XTRA_SIZE kB."
    fi
else
    XTRA_SIZE=0
fi

if [ "$USE_OTHERS" = "yes" -a ! -d $others ]; then
    echo "$prog:  other files directory \"$others\" specified with -X does not exist"
    usage
    clean_and_exit
fi

if [ "$USE_OTHERS" = "yes" ]; then
    others=`fullpath $others`
    OTHER_SIZE=`du -sk $others | ${AWK} '{print $1}'`
    if [ "$VERBOSE" = "yes" ]; then
	echo "Other files directory full path name is \"$others\".  It contains $OTHER_SIZE kB."
    fi
else
    OTHER_SIZE=0
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
	case $pkg in
	# this allows foo.tgz to have a foo.txt containing some readme info
	# about the file to exist without throwing off cdpack.
	*.txt)
		continue
		;;
	esac

	if [ -f $pkg ]; then
		# extract the packge name
		pkgname=`basename $pkg .tgz`

		# extract the packing list
		cat $pkg | (cd $TMP; tar --fast-read -xzf - +BUILD_INFO +CONTENTS)

		# extract the depends
		deps=`${AWK} '/^@pkgdep/ {printf("%s ",$2)}' $TMP/+CONTENTS`

		# extract any conflicts
		cfls=`${AWK} '/^@pkgcfl/ {printf("%s ",$2)}' $TMP/+CONTENTS`

		# check to see if we're allowed to add this package to the CD set
		NO_BIN_ON_CDROM=`${AWK} -F "=" '/NO_BIN_ON_CDROM/ {print $2}' $TMP/+BUILD_INFO`
		if [ ! -z "$NO_BIN_ON_CDROM" ]; then
		    if [ "$ALLOW_NO_BIN_ON_CDROM" = "no" ]; then
		    	echo "EXCLUDED $pkgname:  NO_BIN_ON_CDROM=$NO_BIN_ON_CDROM" >> $restricted
			if [ "$VERBOSE" = "yes" ]; then
			    echo "Excluding $pkg because NO_BIN_ON_CDROM=$NO_BIN_ON_CDROM"
			    echo "$pkgname" >> $exclude
			fi
		    else
		    	echo "INCLUDED $pkgname:  NO_BIN_ON_CDROM=$NO_BIN_ON_CDROM" >> $restricted
		    fi
		fi
		NO_BIN_ON_FTP=`${AWK} -F "=" '/NO_BIN_ON_FTP/ {print $2}' $TMP/+BUILD_INFO`
		if [ ! -z "$NO_BIN_ON_FTP" ]; then
		    if [ "$ALLOW_NO_BIN_ON_FTP" = "no" ]; then
		        echo "EXCLUDED $pkgname:  NO_BIN_ON_FTP=$NO_BIN_ON_FTP" >> $restricted
			if [ "$VERBOSE" = "yes" ]; then
			    echo "Excluding $pkg because NO_BIN_ON_FTP=$NO_BIN_ON_FTP"
			    echo "$pkgname" >> $exclude
			fi
		    else
		        echo "INCLUDED $pkgname:  NO_BIN_ON_FTP=$NO_BIN_ON_FTP" >> $restricted
		    fi
		fi

		# cleanup
		rm $TMP/+CONTENTS $TMP/+BUILD_INFO

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

		npkgs=`${EXPR} $npkgs + 1`
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
${SORT} -u ${deptree}.bak > ${deptree}
${TSORT} $deptree > $order

#
# Run the awk program which figures out which packages go on which CD.
# This program also creates subdirectories and populates them with
# links to the actual binary pacakges.
#
#    packages = ARGV[1];
#    cddir    = ARGV[2];
#    deptree  = ARGV[3];
#    exclude  = ARGV[4];
#    order    = ARGV[5];
#    cdlist   = ARGV[6];
#
if [ "$VERBOSE" = "yes" ]; then
    echo "${AWK} -f @prefix@/libexec/cdgen.awk $packages $cddir $deptree $exclude $order $cdlist dup=$DUP verbose=$VERBOSE dvd=$DVD $XTRA_SIZE $OTHER_SIZE"
fi
${AWK} -f @prefix@/libexec/cdgen.awk $packages $cddir $deptree $exclude $order $cdlist dup=$DUP verbose=$VERBOSE dvd=$DVD $XTRA_SIZE $OTHER_SIZE

if [ $? -ne 0 ]; then
    echo "$prog:  ERROR:  cdgen.awk has failed"
    clean_and_exit
fi

#
# Generate a README
#
if [ "$DVD" = "yes" ]; then
    what="DVD"
    space="   "
else
    what="CD-ROM"
    space=""
fi

cat <<EOF > $readme
This is @DISKNAME@ of a @NDISKS@-disk ${what} collection
containing binary packages for version ${RELEASE} of
the ${OS} operating system running on a ${ARCH} platform.

These binary packages were created with the NetBSD packages
colection (pkgsrc).  For information on the NetBSD package
collection, please visit the NetBSD pkgsrc homepage at

    http://www.pkgsrc.org

For more information about the NetBSD project, please visit the
project's homepage at

    http://www.NetBSD.org

EOF

if [ "$DUP" = "yes" ]; then
cat <<EOF >> $readme
The packages on this ${what} have been arranged to eliminate all
inter-${what} dependencies.  In other words, each package on this
${what} should have all of its dependencies (if they are allowed
to be provided on a ${what}) present on the same ${what}.
Installation of an individual package on this ${what} should not
require any swapping of media.  Some packages may be duplicated on
multiple ${what}s.

EOF
else

cat <<EOF >> $readme
The packages on this ${what} have been arranged by order of their
dependencies across the entire @NDISKS@ set of ${what}s.  This allows
you to make a single pass through the ${what} set when installing
any group of pacakges provided on the set, or when installing or
loading the entire collection.

EOF
fi

#
# NO_BIN_ON_CDROM Comment
#

if [ "$ALLOW_NO_BIN_ON_CDROM" = "no" ]; then
cat <<EOF >> $readme
All packages with NO_BIN_ON_CDROM set have been excluded from
this ${what} collection.
EOF
else
cat <<EOF >> $readme
This ${what} collection includes packages with NO_BIN_ON_CDROM set.
Please do not violate license agreements by selling this ${what}
without verifying that you are allowed to.  A list of these
packages may be found in the ".restricted" file on this ${what}.
EOF
fi

#
# NO_BIN_ON_FTP Comment
#

if [ "$ALLOW_NO_BIN_ON_FTP" = "no" ]; then
cat <<EOF >> $readme
All packages with NO_BIN_ON_FTP set have been excluded from
this ${what} collection.
EOF
else
cat <<EOF >> $readme
This ${what} collection includes packages with NO_BIN_ON_FTP set.
Please do not violate license agreements by placing this image or
its contents on a public FTP site without verifying that you are
allowed to.  A list of these packages may be found in the
".restricted" file on this ${what}.
EOF
fi

#
# cdpack Comment
#
cat <<EOF >> $readme

This file, along with the ${what} layout was created using the
cdpack program which is available as part of the NetBSD
packages collection at 

ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/pkgtools/cdpack/

EOF

#
# Generate an index file which lists the contents of each CD.
#

echo "Creating Disk Index File"

numdisks=0
for cdname in `cat ${cdlist}`
do
    #
    # cdgen shouldn't have included any restricted pkgs, but
    # make 100% sure now!
    #
    if [ "$VERBOSE" = "yes" ]; then
	echo "Removing any leftover restricted packages from $cdname"
    fi
    for pkg in `cat $exclude`
    do
	rm -f ${cddir}/${cdname}/packages/*/$pkg
    done

    if [ "$VERBOSE" = "yes" ]; then
	echo "Creating index for $cdname"
    fi
    for pkg in ${cddir}/${cdname}/packages/All/*
    do
	echo "`basename $pkg`  $cdname" >> $indexf
    done
    numdisks=`${EXPR} ${numdisks} + 1`
done
mv $indexf ${indexf}.tmp
${SORT} ${indexf}.tmp > $indexf

#
# Populate the cd's with the index file and readme
# actually copy these over since the originals will
# be deleted from their temporary directories
#
# Also make symlinks to the stuff in the extra directory
# specified with the -x flag.
#

if [ "$VERBOSE" = "yes" ]; then
    echo "Copying .index and .restricted files to the image directories."
fi

ncds=0
for cdname in `cat $cdlist`
do
    if [ -f $indexf ]; then
	(cd ${cddir}/${cdname} && cp $indexf .index)
    fi

    if [ -f $restricted ]; then
	(cd ${cddir}/${cdname} &&  cp $restricted .restricted)
    fi

    if [ "$ADD_README" = "yes" ]; then
	if [ "$VERBOSE" = "yes" ]; then
	    echo "Copying README.txt file"
	fi
       (cd ${cddir}/${cdname} && sed -e "s/@DISKNAME@/$cdname/g" \
		-e "s/@NDISKS@/${numdisks}/g" \
		< $readme > README.txt)
    fi

    if [ $USE_XTRA = "yes" ]; then
	for f in $extra/*
	do
	    (cd ${cddir}/${cdname} && ln -sf $f)
	done
    fi

    ncds=`${EXPR} $ncds + 1`
done


if [ "$USE_OTHERS" = "yes" ]; then
    if [ "$VERBOSE" = "yes" ]; then
	echo "Creating symlinks from $others (specified with -X) to ${cddir}/${cdname}"
    fi
    cdname=`tail -1 $cdlist`
    for f in $others/*
    do
	(cd ${cddir}/${cdname} && ln -sf $f)
    done
fi

#
# Create the ISO Images
#
volid=PkgsrcDisk
#mkisofs_flags="-f -l -r -J -allow-leading-dots -volset-size $ncds -V $volid "
mkisofs_flags="-v -v -f -l -r -J -allow-leading-dots "

echo "Creating the ISO images"
cdn=1
for cdname in `cat $cdlist`
do
    echo "----------- $cdname ----------"
    #mkisofs_flags2=" -volset-ID $cdname -volset-seqno $cdn "
    mkisofs_flags2=" -V ${volid}$cdn "
    echo "( cd ${cddir} && mkisofs $mkisofs_flags $mkisofs_flags2 -o ${cdname}.iso $cdname >> $mkisofslog 2>&1)"
    ( cd ${cddir} && mkisofs $mkisofs_flags $mkisofs_flags2 -o ${cdname}.iso $cdname >> $mkisofslog 2>&1)
    if [ $? != 0 ]; then
	echo "mkisofs failed"
	clean_and_exit
    fi
    cdn=`${EXPR} $cdn + 1`
done

echo "ISO Images are available in $cddir"

if [ -f $warnings ]; then
	echo "There were warnings generated:"
	cat $warnings
fi

echo "-----------------------------------------------------------"
echo "* Please note:  This ${what} set was created with          ${space}*"
echo "*                                                         *"
if [ "$ALLOW_NO_BIN_ON_CDROM" = "no" ]; then
    echo "*   - NO_BIN_ON_CDROM packages excluded.                  *"
else
    echo "*   - NO_BIN_ON_CDROM packages INCLUDED.  Please          *"
    echo "*     verify that you will not violate any licenses       *"
    echo "*     with this ${what} set.  Refer to the /.restricted    ${space}*"
    echo "*     file which has been placed on each ${what} in the    ${space}*"
    echo "*     set for details.                                    *"
fi
echo "*                                                         *"
if [ "$ALLOW_NO_BIN_ON_FTP" = "no" ]; then
    echo "*   - NO_BIN_ON_FTP packages excluded.                    *"
else
    echo "*   - NO_BIN_ON_FTP packages INCLUDED.  You should        *"
    echo "*     not make this ${what} set available via FTP as it    ${space}*"
    echo "*     would violate the license on one or more            *"
    echo "*     packages.  Refer to the /.restricted file           *"
    echo "*     which has been placed on each ${what} in the         ${space}*"
    echo "*     set for details.                                    *"
fi
echo "*                                                         *"
echo "-----------------------------------------------------------"

echo " "
echo "$prog finished: `date`"
echo " "

if [ "x$DEBUG" = "xno" ]; then
    rm -fr $TMP
else
    echo "Debugging output left in $TMP"
fi

exit 0
