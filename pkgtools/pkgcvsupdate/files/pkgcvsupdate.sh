#! /bin/sh -
# $NetBSD: pkgcvsupdate.sh,v 1.1.1.1 2001/11/29 14:13:27 seb Exp $

BASENAME=@BASENAME@
DIRNAME=@DIRNAME@
GREP=@GREP@
LS=@LS@
MAKE=@MAKE@
TEST=@TEST@

args="$@"
cwd=`pwd`

# get packages to update for a start
if $TEST -f ../../Packages.txt && $TEST -d ../../pkgtools/digest ; then
	# we are in a package directory: only one package to start with
	start_pkgs=`$MAKE show-var VARNAME=PKGPATH`
	if $TEST $? -ne 0 || $TEST x"$start_pkgs" = x ; then
		exit 1
	fi
	pkgsrcdir=`$MAKE show-var VARNAME=PKGSRCDIR`
	if $TEST $? -ne 0 || $TEST x"$pkgsrcdir" = x ; then
		exit 1
	fi
elif $TEST -f Makefile && $TEST -f ../Packages.txt ; then
	# we are in category directory: get the package list of this
	# category
	pkg_list=`$MAKE -V SUBDIR`
	if $TEST $? -ne 0 || $TEST x"$start_pkgs" = x ; then
		# perhaps we don't have the -V flags to make (pre NetBSD 1.3
		# make ?)
		pkg_list=""
		for f in * ; do
			if $TEST -f $f/Makefile ; then
				pkg_list="$pkg_list $f"
			fi
		done
	fi
	category=`$BASENAME $cwd`
	if $TEST $? -ne 0 || $TEST x"$category" = x ; then
		exit 1
	fi
	start_pkgs=""
	for p in $pkg_list ; do
		start_pkgs="$start_pkgs $category/$p"
	done
	pkgsrcdir=`$DIRNAME $cwd`
	if $TEST $? -ne 0 || $TEST x"$pkgsrcdir" = x ; then
		exit 1
	fi
else
	echo "Not in a package or category directory" 1>&2
	exit
fi

# first update pkgsrc infrastructure...
cd $pkgsrcdir/mk || exit 1
echo "==> mk"
cvs update $@ || exit 1

# ... then needed packages
pkg_toupdate=$start_pkgs
pkg_updated=""
while true; do
	# get next package to update
	set blah $pkg_toupdate
	shift
	pkg=$1
	if $TEST x"$pkg" = x ; then
		break # all done
	fi
	shift
	pkg_toupdate="$*"
	# check if we already updated it...
	case :$pkg_updated: in
		*:$pkg:*) continue ;; # ...yes: on to next one
	esac
	# ...no: updating it
	if cd $pkgsrcdir/$pkg ; then :; else
		# package directory is not there, this may be a new package:
		# try to check it out. This would also fail if it is
		# a brand new category! Oh well...
		cd $pkgsrcdir/`$BASENAME $pkg` || exit 1
		cvs checkout $args `$DIRNAME $pkg` || exit 1
	fi
	echo "==> $pkg"
	cvs update $args || exit 1
	# record we updated if
	pkg_updated="$pkg_updated:$pkg"
	# queue dependency packages
	pkg_depends=`$MAKE show-depends-dirs`
	if $TEST $? -ne 0 ; then
		exit 1
	fi
	pkg_toupdate="$pkg_toupdate $pkg_depends"	
done
