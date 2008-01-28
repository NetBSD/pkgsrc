#!/bin/sh
# $NetBSD: cddist.sh,v 1.1 2008/01/28 23:06:13 dmcmahill Exp $
#
# Copyright (c) 2008 Dan McMahill, All rights reserved.
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
# $2 = distfiles directory (/usr/pkgsrc/distfiles)
# $3 = output directory

prog=cddist
progver=@progver@

TMPDIR=${TMPDIR:-/tmp}
TMP=${TMPDIR}/${prog}.$$
AWK=${AWK:-@AWK@}
EXPR="@EXPR@"
PRINTF="@PRINTF@"
SORT="@SORT@"

sizes=$TMP/sizes
sorted=$TMP/sorted

cdlist=$TMP/cdlist
indexf=$TMP/indexf
readme=$TMP/readme
warnings=$TMP/warnings


rm -fr $TMP
mkdir -m 0700 $TMP
if test $? -ne 0 ; then
    echo "Could not create temporary directory $TMP"
    exit 1
fi

touch $exclude

usage(){
    cat << EOF
$prog - generates ISO9660 images for a multi-cd/dvd pkgsrc distfiles archive
Usage:      $prog [-dvd] [-h|--help] [-l logfile] [-dRvV]
            [-x dir] [-X dir] distfiles_directory cdimage_directory
Example:    $prog /usr/pkgsrc/packages/distfiles  /images/distfiles
Please refer to the manual page for complete documentation."
	
EOF
echo " "
}

clean_and_exit(){
    if test $# -ge 1 ; then
	rc=$1
    else
	rc=0
    fi
    if [ "x$DEBUG" = "xno" ]; then
	rm -fr $TMP
    else
	echo "Debugging output left in $TMP"
    fi
    exit $rc
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
DEBUG=no
VERBOSE=no
VERSION=no
USE_XTRA=no
USE_OTHERS=no
mkisofslog=/dev/null

DVD=no

while
    test -n "$1"
do
    case "$1"
    in
	# enable debugging
	-d) DEBUG=yes
	    shift
	    ;;

	# make a DVD sized image
	-dvd) DVD=yes
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
	    clean_and_exit 1
	    ;;

	*)  ARGS="$ARGS $1"
	    shift
	    ;;
    esac
done

if [ $VERSION = "yes" ]; then
    echo "$prog-$progver"
    clean_and_exit 0
fi

set -- $ARGS

if [ $# -ne 2 ]; then
	echo "$prog:  wrong number of arguments"
	usage
	clean_and_exit 1
fi

distfiles=$1
cddir=$2

if [ "$VERBOSE" = "yes" ]; then
    echo "Verbose output is on"

    if [ "$DVD" = "yes" ]; then
	echo "A DVD sized image will be created"
    else
	echo "A CD-ROM sized image will be created"
    fi
fi

#
# Make sure all required directories and files exist
#

if [ ! -d $distfiles ]; then
    echo "$prog:  packages directory \"$distfiles\" does not exist"
    usage
    clean_and_exit 1
else
    distfiles=`fullpath $distfiles`
fi

if [ ! -d $cddir ]; then
    echo "$prog:  cd image directory \"$cddir\" does not exist"
    usage
    clean_and_exit 1
else
    cddir=`fullpath $cddir`
fi

if [ "$USE_XTRA" = "yes" -a ! -d $extra ]; then
    echo "$prog:  extra directory \"$extra\" specified with -x does not exist"
    usage
    clean_and_exit 1
fi

if [ "$USE_XTRA" = "yes" ]; then
    extra=`fullpath $extra`
    XTRA_SIZE=`du -sk $extra | ${AWK} '{print $1 * 1024}'`
    if [ "$VERBOSE" = "yes" ]; then
	echo "Extra directory full path name is \"$extra\".  It contains $XTRA_SIZE bytes."
    fi
else
    XTRA_SIZE=0
fi

if [ "$USE_OTHERS" = "yes" -a ! -d $others ]; then
    echo "$prog:  other files directory \"$others\" specified with -X does not exist"
    usage
    clean_and_exit 1
fi

if [ "$USE_OTHERS" = "yes" ]; then
    others=`fullpath $others`
    OTHER_SIZE=`du -sk $others | ${AWK} '{print $1 * 1024}'`
    if [ "$VERBOSE" = "yes" ]; then
	echo "Other files directory full path name is \"$others\".  It contains $OTHER_SIZE bytes."
    fi
else
    OTHER_SIZE=0
fi

echo " "
echo "$prog starting: `date`"
echo " "

find_size() {
    d=$1
    if test $# -eq 1 ; then
	sz=0
    else
	sz=$2
    fi
    test "$VERBOSE" = "yes" && echo "find_size $d $sz" >/dev/stderr

    szf=0
    if test -f $d ; then
	szf=`wc -c $d | ${AWK} '{print $1}'`
    elif test -d $d ; then
	for f in $d/* ; do
	    szf=`find_size $f $szf`
	done
    else
	echo "WARNING:  I do not know what to do with" >/dev/stderr
	echo "     $d">/dev/stderr
	echo "which is neither a file nor a directory" >/dev/stderr
    fi
    
    tot=`${EXPR} $sz + $szf`
    test "$VERBOSE" = "yes" && echo "    return $tot" >/dev/stderr
    echo "$tot"
}


ndist=0
echo "Extracting sizes for the distfiles ..."
rm -f $sizes
here="`pwd`"
cd $distfiles
for d in *
do
    case $d in
	CVS)
	    echo "Skip CVS directory"
	    ;;
	*)
	    sz=`find_size $d`
	    echo "$d $sz" >> $sizes
	    ndist=`${EXPR} $ndist + 1`
    esac
done
cd "$here"

echo " "
echo "Finished extracting sizes for $ndist distfiles"
echo " "

#
# sort the distfiles alphabetically
#
${SORT} $sizes > $sorted

#
# Create directories for each image and populate the directories
# with symlinks that will be resolved when we actually create the
# ISO image
#
if [ "$DVD" = "yes" ]; then
    what="DVD"
    space="   "
    capacity=4300000000
else
    what="CD-ROM"
    space=""
    capacity=700000000
fi

new_image() {
    cdn=`${EXPR} $cdn + 1`
    dest=$cddir/disk$cdn
    mkdir -p $dest/distfiles
    echo "disk$cdn" >> $cdlist
    cds=${XTRA_SIZE}
}

cdn=0
new_image
cds=`${EXPR} $cds + ${OTHER_SIZE}`
cat $sorted | while read f s ; do
    newsize=`${EXPR} $cds + $s`

    # use awk instead of test because we overflow the 32 bit
    # signed values used by test when we're using a DVD image
    full=`echo "$newsize $capacity" | \
	${AWK} '{if($1 > $2) {print "yes"} else {print "no"}}'`
    if test "$full" = "no" ; then
	echo "Add $f to image #$cdn to increase the size to $newsize"
	cds=$newsize
	ln -sf $distfiles/$f $dest/distfiles/$f
    else
	new_image
	cds=`${EXPR} $cds + $s`
	echo "Add $f to new image #$cdn with starting size $s"
	ln -sf $distfiles/$f $dest/distfiles/$f
    fi
done

#
# Generate a README
#

cat <<EOF > $readme
This is @DISKNAME@ of a @NDISKS@-disk ${what} collection
containing an archive of distfiles used by the NetBSD
pkgsrc system.

For information on the NetBSD package collection, please visit
the NetBSD pkgsrc homepage at

    http://www.pkgsrc.org

For more information about the NetBSD project, please visit the
project's homepage at

    http://www.NetBSD.org

Please do not distribute this ${what} set unless you have verified
that the individual licenses of all the distfiles allows you to.
It is anticipated that the primary use of this ${what} set is
not for distribution, but rather for archiving.  Some licenses
require that if you distribute a binary package that you are willing
to provide sources on request.  By archiving the distfiles, you are
ensuring that you are able to fulfill such a request.

EOF


#
# cdpack Comment
#
cat <<EOF >> $readme

This file, along with the ${what} layout was created using the
cddist program which is available as part of the cdpack package
in the NetBSD packages collection at 

ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/pkgtools/cdpack/

EOF

#
# Generate an index file which lists the contents of each CD.
#

echo "Creating Disk Index File"

show_files() {
    d="$1"
    path=
    if test -d "$d" ; then 
	for fs in $d/* ; do
	    show_files $fs
	done
    else
	${PRINTF} "%-60s %s\n" $d  $cdname >> $indexf
    fi
}

numdisks=0
for cdname in `cat ${cdlist}`
do
    if [ "$VERBOSE" = "yes" ]; then
	echo "Creating index for $cdname"
    fi
    cd ${cddir}/${cdname}/distfiles && for d in *
    do
	show_files $d
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
    echo "Copying .index file to the image directories."
fi

ncds=0
for cdname in `cat $cdlist`
do
    if [ -f $indexf ]; then
	(cd ${cddir}/${cdname} && cp $indexf .index)
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
volid=DistDisk
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
	clean_and_exit 1
    fi
    cdn=`${EXPR} $cdn + 1`
done

echo "ISO Images are available in $cddir"

if [ -f $warnings ]; then
	echo "There were warnings generated:"
	cat $warnings
fi

cat <<EOF

-----------------------------------------------------------------
* Please note:  This ${what} set may contain files which may     ${space}*
* not be redistributed.  Before you distribute this set you     *
* must verify that you will not violate any licenses  with this *
* ${what} set.                                                   ${space}*
-----------------------------------------------------------------

$prog finished: `date`

EOF

clean_and_exit 0

