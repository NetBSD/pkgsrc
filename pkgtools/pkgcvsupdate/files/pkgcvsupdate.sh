#! /bin/sh -
# $NetBSD: pkgcvsupdate.sh,v 1.3 2002/01/07 12:39:25 seb Exp $

AWK=@AWK@
BASENAME=@BASENAME@
DIRNAME=@DIRNAME@
GREP=@GREP@
LS=@LS@
MAKE=@MAKE@
SED=@SED@
TEST=@TEST@

cvs_cmd_args="$@"
cwd=`pwd`
dirs_updated=":"

# low-level cvs update
cvs_update()
{
_cwd=`pwd`
if $TEST "x$1" = x. ; then
	echo "==> $_cwd"
else
	echo "==> $_cwd/$1"
fi
cvs ${CVS_OPTIONS} update $cvs_cmd_args $1 || return 1
}

# update a directory tree
cvs_update_dir()
{
_cwd=`pwd`
case $dirs_updated in
	*:$_cwd:*) return 0;; # already updated
esac
cvs_update . || return 1
dirs_updated="$dirs_updated$_cwd:"
}

# get the file included in ./Makefile
get_make_included_files()
{
$GREP '^\.include' Makefile | \
$AWK '$2 !~ /mk\//{ gsub(/["<>]/, "", $2); print $2 }' || exit 1
}

# get the "make sub-directory"
get_subdirs()
{
# update local files first
_oldcvs_cmd_args="$cvs_cmd_args"
cvs_cmd_args="-l $cvs_cmd_args"
cvs_update . || return 1
cvs_cmd_args="$oldcvs_cmd_args"
subdirs=`$MAKE -V SUBDIR`
if $TEST $? -ne 0 || $TEST x"$subdirs" = x ; then
	# perhaps we don't have the -V flags to make (pre NetBSD 1.3
	# make ?)
	# XXX FIXME: we could miss a new directory here
	subdirs=""
	for _f in * ; do
		if $TEST -f $_f/Makefile ; then
			subdirs="$subdirs $_f"
		fi
	done
fi
}

# update a list of package directories and their dependencies
recursive_cvs_update_pkgdir()
{
_dirs_toupdate="$*"
while true ; do
	# get the next package directory to update
	set blah $_dirs_toupdate
	shift
	_dir=$1
	if $TEST x"$_dir" = x ; then
		break # all done
	fi
	shift
	_dirs_toupdate="$*"
	# cd into it and update...
	if $TEST -d $_dir ; then 
		cd $_dir || exit 1
		cvs_update_dir
	else
		# ...the directory does not exist, that would be a brand new
		# package we try to check it out instead
		cd `$DIRNAME $_dir` || exit 1
		cvs ${CVS_OPTIONS} checkout $cvs_cmd_args `$BASENAME $_dir` || exit 1
		cd $_dir || exit 1
	fi
	_cwd=`pwd`
	# get the dependencies...
	_depends=`$MAKE show-depends-dirs`
	if $TEST $? -ne 0; then
		# ...it failed try to see if it's because included Makefile
		# fragments are missing and queue up the packages providing
		# them
		_included_files=`get_make_included_files`
		for _f in $_included_files ; do
			case x$_f in
				x../*)
					_dirs_toupdate="$_cwd/`$DIRNAME $_f` $_dirs_toupdate";;	
			esac
		done
		# and we would like to visit again the current package
		# directory in the end
		dirs_updated=`echo $dirs_updated | $SED -e "s,:$_cwd:,:,"`
		_dirs_toupdate="$_dirs_toupdate $_cwd"
	else
		# queue up the dependencies of the current package
		for _p in $_depends ; do
			_dirs_toupdate="$_cwd/../../$_p $_dirs_toupdate"
		done
	fi
done
}

if $TEST -f ../../Packages.txt && $TEST -d ../../pkgtools/digest ; then
	# we are in a package directory...

	# update mk
	cd ../../mk && cvs_update_dir && cd $cwd || exit 1

	# update the current package directory and needed dependencies
	recursive_cvs_update_pkgdir $cwd
	
elif $TEST -f Makefile && \
	( $TEST -f ../Packages.txt || $TEST -f Packages.txt) ; then
	# we are in category directory or in the top-level pkgsrc directory

	# update mk
	$TEST -d ../mk && cd ../mk || cd mk || exit 1
	cvs_update_dir && cd $cwd || exit 1

	# get the packages in this category or all the categories
	get_subdirs
	if $TEST $? -ne 0 || $TEST x"$subdirs" = x ; then
		echo "could not get the sub-directories in $cwd" 1>&2
		exit 1
	fi

	if $TEST -f ../Packages.txt ; then
		# update the category packages' directories and their
		# dependencies
		_dirs=""
		for _p in $subdirs ; do
			_dirs="$_dirs $cwd/$_p"
		done
		recursive_cvs_update_pkgdir $_dirs
	else
		for _p in $subdirs ; do
			cvs_update $_p || exit 1
		done
	fi
else
	echo "Not in a package, category or toplevel directory" 1>&2
	exit 1
fi
