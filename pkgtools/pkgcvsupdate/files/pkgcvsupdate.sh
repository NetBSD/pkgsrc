#! /bin/sh -
# $NetBSD: pkgcvsupdate.sh,v 1.2 2001/11/30 12:16:08 seb Exp $

AWK=@AWK@
BASENAME=@BASENAME@
DIRNAME=@DIRNAME@
GREP=@GREP@
LS=@LS@
MAKE=@MAKE@
SED=@SED@
TEST=@TEST@

args="$@"
cwd=`pwd`
dirs_updated=":"

cvs_update()
{
_cwd=`pwd`
case $dirs_updated in
	*:$_cwd:*) return 0;; # already updated
esac
echo "==> $_cwd"
cvs ${CVS_OPTIONS} update $args || return 1
dirs_updated="$dirs_updated$_cwd:"
}

get_make_included_files()
{
$GREP '^\.include' Makefile | \
$AWK '$2 !~ /mk\//{ gsub(/["<>]/, "", $2); print $2 }' || exit 1
}

recursive_cvs_update()
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
		cvs_update
	else
		# ...the directory does not exist, that would be a brand new
		# package we try to check it out instead
		cd `$DIRNAME $_dir` || exit 1
		cvs ${CVS_OPTIONS} checkout $args `$BASENAME $_dir` || exit 1
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
	cd ../../mk && cvs_update && cd $cwd || exit 1

	# update the current package directory and needed dependencies
	recursive_cvs_update $cwd
	
elif $TEST -f Makefile && $TEST -f ../Packages.txt ; then
	# we are in category directory: get the package list of this
	# category

	# update mk
	cd ../mk && cvs_update && cd $cwd || exit 1

	# get the packages in this category
	_list=`$MAKE -V SUBDIR`
	if $TEST $? -ne 0 || $TEST x"$_list" = x ; then
		# perhaps we don't have the -V flags to make (pre NetBSD 1.3
		# make ?)
		_list=""
		for _f in * ; do
			if $TEST -f $_f/Makefile ; then
				_list="$_list $_f"
			fi
		done
	fi
	_dirs=""
	for _p in $_list ; do
		_dirs="$_dirs $cwd/$_p"
	done

	# update the category packages' directories and their dependencies
	recursive_cvs_update $_dirs
else
	echo "Not in a package or category directory" 1>&2
	exit 1
fi
