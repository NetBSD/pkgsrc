#!/bin/sh -e
#
# $Id: pkgchk.sh,v 1.44 2003/09/16 14:36:12 abs Exp $
#
# TODO: Handle updates with dependencies via binary packages

PATH=/usr/sbin:/usr/bin:${PATH}

check_packages_installed()
    {
    UPDATE_TODO=
    MISSING_TODO=
    MISMATCH_TODO=

    for pkgdir in $* ; do

	if [ ! -f $PKGSRCDIR/$pkgdir/Makefile ];then
	    echo "WARNING: No $pkgdir/Makefile - package moved or obsolete?"
	    continue
	fi
	cd $PKGSRCDIR/$pkgdir
	if [ -n "$opt_B" ];then
	    extract_make_vars PKGNAME FILESDIR PKGDIR DISTINFO_FILE PATCHDIR
	else
	    extract_make_vars PKGNAME
	fi
	if [ -z "$PKGNAME" ]; then
	    echo "Unable to extract PKGNAME for $pkgdir"
	    exit 1
	fi
	if [ ! -d $PKG_DBDIR/$PKGNAME ];then
	    echo_n "$PKGNAME: "
	    pkg=`echo $PKGNAME | sed 's/-[0-9].*//'`
	    pkginstalled=`sh -c "${PKG_INFO} -e $pkg" || true`
	    INSTALL=
	    if [ -n "$pkginstalled" ];then
		echo_n "version mismatch - $pkginstalled"
		MISMATCH_TODO="$MISMATCH_TODO $pkginstalled"
		UPDATE_TODO="$UPDATE_TODO $PKGNAME $pkgdir"
	    else
		echo_n "missing"
		MISSING_TODO="$MISSING_TODO $PKGNAME $pkgdir"
	    fi
	    if [ -f $PACKAGES/All/$PKGNAME.tgz ] ;then
		echo_n " (binary package available)"
	    fi
	    echo
	else
	    if [ -n "$opt_B" ];then
		current_build_ver=`get_build_ver`
		installed_build_ver=`sed "s|^[^:]*/[^:]*:||" $PKG_DBDIR/$PKGNAME/+BUILD_VERSION`
		if [ x"$current_build_ver" != x"$installed_build_ver" ];then
		    echo "$PKGNAME: build version information mismatch"
		    MISMATCH_TODO="$MISMATCH_TODO $PKGNAME"
		    # should we mark this pkg to be updated if -u is given ??
		elif [ -n "$opt_v" ];then
		    echo "$PKGNAME: OK"
		fi
	    elif [ -n "$opt_v" ];then
		echo "$PKGNAME: OK"
	    fi
	fi
    done
    }

echo_n()
    {
    echo $ac_n "$*"$ac_c
    }

extract_make_vars()
    {
    MAKEDATA=".PHONY: x\nx:\n";
    for var in $* ; do
	MAKEDATA=$MAKEDATA"\t@echo $var=\${$var}\n"
    done
    eval `printf "$MAKEDATA" | ${MAKE} -f - -f Makefile x | \
					sed -e 's/[^=]*=/&"/' -e 's/$/"/'`
    }

# $1 = name of variable
# $2 = default value
extract_mk_dir_var()
    {
    if [ -z "`eval echo \\$$1`" ] ; then
	eval `printf "BSD_PKG_MK=1\n.PHONY: x\nx:\n\t@echo $1="'$'"{$1}\n" | ${MAKE} -f - -f $MAKECONF x`
	if [ -z "`eval echo \\$$1`" ]; then
	    eval "$1=$2"
	fi
	if [ ! -d `eval echo \\$$1` ];then
	    echo "Unable to locate $1 `eval echo \\$$1`"
	    exit 1;
	fi
    fi
    }

extract_variables()
    {
    extract_mk_dir_var PKGSRCDIR /usr/pkgsrc
    extract_mk_dir_var PKG_DBDIR /var/db/pkg

    # Now we have PKGSRCDIR, use it to determine PACKAGES, and PKGCHK_CONF
    # as well as AWK, GREP, SED, PKGCHK_TAGS and PKGCHK_NOTAGS
    #

    cd $PKGSRCDIR/pkgtools/pkgchk
    extract_make_vars AWK GREP SED PACKAGES PKG_INFO PKG_ADD PKG_DELETE \
		      PKGCHK_CONF PKGCHK_TAGS PKGCHK_NOTAGS

    if [ -z "$PACKAGES" ];then
	PACKAGES=$PKGSRCDIR/packages
    fi

    if [ -z "$PKGCHK_CONF" ];then
	PKGCHK_CONF=$PKGSRCDIR/pkgchk.conf
    fi
    }

get_build_ver()
    {
    files=""
    for f in Makefile ${FILESDIR}/* ${PKGDIR}/*; do
	if [ -f $f ];then
	    files="$files $f"
	fi
    done
    if [ -f ${DISTINFO_FILE} ]; then
	for f in `${AWK} 'NF == 4 && $3 == "=" { gsub("[()]", "", $2); print $2 }' < ${DISTINFO_FILE}`; do 
	    if [ -f ${PATCHDIR}/$f ]; then
		files="$files ${PATCHDIR}/$f";
	    fi;
	done
    fi
    if [ -d ${PATCHDIR} ]; then
	for f in ${PATCHDIR}/patch-*; do
	    case $f in
	    *.orig|*.rej|*~) ;;
	    ${PATCHDIR}/patch-local-*)
		files="$files $f" ;;
	    esac
	done
    fi
    cat $files | ${GREP} '\$NetBSD'
    }

pkg_fetch()
    {
    PKGNAME=$1
    PKGDIR=$2

    run_cmd "cd $PKGSRCDIR/$PKGDIR && ${MAKE} fetch-list | sh"
    if [ -n "$FAIL" ]; then
	FAIL_DONE=$FAIL_DONE" "$PKGNAME
    else
	FETCH_DONE=$FETCH_DONE" "$PKGNAME
    fi
    }

pkg_install()
    {
    PKGNAME=$1
    PKGDIR=$2
    INSTALL=$3

    if [ -d $PKG_DBDIR/$PKGNAME ];then
	echo "$PKGNAME installed in previous stage"
    elif [ -n "$opt_b" -a -f $PACKAGES/All/$PKGNAME.tgz ] ; then
	if [ $INSTALL = Update ];then
	    PKG=`echo $PKGNAME | sed 's/-[0-9].*//'`
	    run_cmd "${PKG_DELETE} $PKG" 1
	    if [ -n "$FAIL" ]; then
		echo "Can only update packages with dependencies via -s"
		exit 1
	    fi
	fi
	if [ -n "$saved_PKG_PATH" ] ; then
	    export PKG_PATH=$saved_PKG_PATH
	fi
	run_cmd "cd $PACKAGES/All && ${PKG_ADD} $PKGNAME.tgz"
	if [ -n "$saved_PKG_PATH" ] ; then
	    unset PKG_PATH
	fi
    elif [ -n "$opt_s" ]; then
	run_cmd "cd $PKGSRCDIR/$PKGDIR && ${MAKE} update CLEANDEPENDS=yes"
    fi

    if [ -z "$opt_n" -a ! -d $PKG_DBDIR/$PKGNAME ];then
	FAIL=1
    fi

    if [ -n "$FAIL" ]; then
	FAIL_DONE=$FAIL_DONE" "$PKGNAME
    elif [ $INSTALL = Update ];then
	UPDATE_DONE=$UPDATE_DONE" "$PKGNAME
    else
	INSTALL_DONE=$INSTALL_DONE" "$PKGNAME
    fi
    }

pkg_fetchlist()
    {
    PKGLIST=$@
    echo "[ Fetch...]"
    while [ $# != 0 ]; do 
	pkg_fetch $1 $2
	shift ; shift;
    done
    }

pkg_installlist()
    {
    INSTALL=$1 ; shift
    echo "[ $INSTALL...]" ;
    while [ $# != 0 ]; do
	pkg_install $1 $2 $INSTALL
	shift ; shift;
    done
    }

run_cmd()
    {
    FAIL=
    if [ -n "$2" ]; then
	FAILOK=$2
    else
	FAILOK=$opt_k
    fi
    echo $1
    if [ -z "$opt_n" ];then
	if [ -n "$opt_L" ] ; then
	    sh -c "$1" > "$opt_L" 2>&1 || FAIL=1
	else
	    sh -c "$1" || FAIL=1
	fi
	if [ -n "$FAIL" ] ; then
            echo "** '$1' failed"
	    if [ -n "$opt_L" ] ; then
		tail -20 "$opt_L"
	    fi
            if [ "$FAILOK" != 1 ]; then
                exit 1
            fi
        fi
    fi
    }

args=`getopt BC:D:L:U:abcfhiknrsuv $*`
if [ $? != 0 ]; then
    opt_h=1
fi
set -- $args
while [ $# != 0 ]; do
    case "$1" in
	-B )    opt_B=1 ; opt_i=1 ;;
	-C )	opt_C="$2" ; shift;;
	-D )	opt_D="$2" ; shift;;
	-L )	opt_L="$2" ; shift;;
	-U )	opt_U="$2" ; shift;;
	-a )	opt_a=1 ; opt_c=1 ;;
	-b )	opt_b=1 ;;
	-c )	opt_c=1 ;;
	-f )	opt_f=1 ;;
	-h )	opt_h=1 ;;
	-i )	opt_i=1 ;;
	-k )	opt_k=1 ;;
	-n )	opt_n=1 ;;
	-r )	opt_r=1 ;;
	-s )	opt_s=1 ;;
	-u )	opt_u=1 ; opt_i=1 ;;
	-v )	opt_v=1 ;;
	-- )	break ;;
    esac
    shift
done

if [ -z "$opt_b" -a -z "$opt_s" ];then
    opt_b=1; opt_s=1;
fi

if [ -z "$opt_a" -a -z "$opt_c" -a -z "$opt_i" ];then
    echo "Must specify at least one of -a, -c, -i, or -u";
    echo
    opt_h=1;
fi

if [ -n "$opt_h" -o $# != 1 ];then
    echo 'Usage: pkg_chk [opts]
	-B      Check the "Build version" of packages (implies -i)
	-C conf Use pkgchk.conf file 'conf'
	-D tags Comma separated list of additional pkgchk.conf tags to set
	-L file Redirect output from commands run into file (should be fullpath)
	-U tags Comma separated list of pkgchk.conf tags to unset
	-a      Add all missing packages (implies -c)
	-b      Limit installations to binary packages
	-c      Check installed packages against pkgchk.conf
	-f      Perform a 'make fetch' for all required packages
	-h      This help
	-i	Check versions of installed packages (not using pkgchk.conf)
	-k	Continue with further packages if errors are encountered
	-n	Display actions that would be taken, but do not perform them
	-r	Recursively remove mismatched files (use with care)
	-s      Limit installations to building from source
	-u      Update all mismatched packages (implies -i)
	-v      Verbose

pkg_chk verifies installed packages against pkgsrc.
The most common usage is 'pkg_chk -i' to check all installed packages.
For more advanced usage, including defining a set of desired packages based
on hostname and type, see pkg_chk(8).
'
    exit 1
fi

# Hide PKG_PATH to avoid breakage in 'make' calls
saved_PKG_PATH=$PKG_PATH
unset PKG_PATH || true

test -n "$MAKE" || MAKE="@MAKE@"
test -n "$MAKECONF" || MAKECONF="@MAKECONF@"
if [ ! -f $MAKECONF ] ; then
    if [ -f /etc/mk.conf ] ; then
	MAKECONF=/etc/mk.conf
    else
	MAKECONF=/dev/null
    fi
fi

# grabbed from GNU configure
if (echo "testing\c"; echo 1,2,3) | grep c >/dev/null; then
  # Stardent Vistra SVR4 grep lacks -e, says ghazi@caip.rutgers.edu.
  if (echo -n testing; echo 1,2,3) | sed s/-n/xn/ | grep xn >/dev/null; then
    ac_n= ac_c='
' ac_t='	'
  else
    ac_n=-n ac_c= ac_t=
  fi
else
  ac_n= ac_c='\c' ac_t=
fi

if [ -n "$opt_L" ] ; then
    rm -f $opt_L
fi

extract_variables
if [ -n "$opt_C" ] ; then
    PKGCHK_CONF=$opt_C
fi

cd $PKGSRCDIR
real_pkgsrcdir=`pwd`

if [ -n "$opt_i" ];then
    PKGDIRLIST=`sh -c "${PKG_INFO} -B \*" | ${AWK} -F= '/PKGPATH=/{print $2" "}'`
fi


if [ -n "$opt_c" ];then

    if [ ! -r $PKGCHK_CONF ];then
	echo "Unable to read PKGCHK_CONF '$PKGCHK_CONF'"
	exit 1;
    fi

    # Determine list of tags
    #
    TAGS="`hostname | sed -e 's,\..*,,'`,`hostname`,`uname -srm | ${AWK} '{print $1"-"$2"-"$3","$1"-"$2","$1"-"$3","$1","$2","$3}'`"
    if [ -f /usr/X11R6/lib/libX11.so -o -f /usr/X11R6/lib/libX11.a ];then
	TAGS="$TAGS,x11"
    fi
    if [ -n "$PKGCHK_TAGS" ];then
	TAGS="$TAGS,$PKGCHK_TAGS"
    fi
    if [ -n "$PKGCHK_NOTAGS" ];then
	if [ -n "$opt_U" ];then
		opt_U="$opt_U,$PKGCHK_NOTAGS"
	else
		opt_U="$PKGCHK_NOTAGS"
	fi
    fi
    if [ -n "$opt_D" ];then
	TAGS="$TAGS,$opt_D"
    fi
    if [ -n "$opt_v" ];then
	echo "set   TAGS=$TAGS"
	echo "unset TAGS=$opt_U"
    fi

    # Extract list of valid pkgdirs (skip any 'alreadyset' in $PKGDIRLIST)
    #
    PKGDIRLIST="$PKGDIRLIST "`${AWK} -v alreadyset="$PKGDIRLIST" -v setlist=$TAGS -v unsetlist=$opt_U '
    BEGIN {
	split(alreadyset, tmp, " ");
	for (tag in tmp) { skip[tmp[tag]] = 1; }

	split(setlist, tmp, ",");
	for (tag in tmp) { taglist[tmp[tag]] = 1; }

	split(unsetlist, tmp, ",");
	for (tag in tmp) { skip[tmp[tag]] = 1; delete taglist[tmp[tag]] }

	taglist["*"] = "*"
    }
    function and_expr_with_dict(expr, dict, ary, i, r) {
	split(expr,ary,/\\+/);
	r = 1;
	for (i in ary)
		if (! (ary[i] in dict))
			{ r = 0; break ;}
	return r;
    }
    {
    sub("#.*", "");
    if (skip[$1])
	{ next; }
    need = 0;
    for (f = 1 ; f<=NF ; ++f) {			# For each word on the line
	if (sub("^-", "", $f)) { 	# If it begins with a '-'
		if ($f ~ /\\+/) {	# If it is a ANDed tag expression
			if (and_expr_with_dict($f, taglist))
				next;		# If it is true, discard
		} else {			# If it is a simple tag
			if ($f in taglist)	# If match, discard
				next;
		}
	} else {
		if ($f ~ /\\+/) {	# If it is a ANDed tag expression
			if (and_expr_with_dict($f, taglist))
				need = 1;	# If it is true, note needed
		} else {			# If it is a simple tag
			if ($f in taglist)	# If match, note needed
				need = 1;
		}
	}
    }
    if (NF == 1 || need)
	{ print $1 }
    }
    ' < $PKGCHK_CONF
    `
fi

# Check $PKGDIRLIST packages are installed and correct version
#
check_packages_installed $PKGDIRLIST

if [ -n "$opt_r" -a -n "$MISMATCH_TODO" ]; then
    run_cmd "${PKG_DELETE} -r $MISMATCH_TODO" 1
    if [ -n "$opt_a" ] ; then
	echo "[ Rechecking packages after deletions ]"
	check_packages_installed $PKGDIRLIST # May need to add more packages
    fi
fi

UPDATE_FETCH_TODO="$UPDATE_TODO"
if [ -n "$UPDATE_TODO" ];then
    # Generate list including packages which depend on updates
    #
    set -- $UPDATE_TODO
    while [ $# != 0 ]; do
	PKGNAME=`echo $1 | sed 's/-[0-9].*//'`
	if [ -f $PKG_DBDIR/$PKGNAME-[0-9]*/+REQUIRED_BY ];then
	    LIST="$LIST$1|$2|`cat $PKG_DBDIR/$PKGNAME-[0-9]*/+REQUIRED_BY | xargs echo`\n"
	else
	    LIST="$LIST$1|$2\n"
	fi
	shift ; shift;
    done

    # drop any packages whose 'parents' are also to be updated
    #
    UPDATE_TODO=`printf "$LIST" | ${AWK} -F '|' '
    {
    pkg2dir[$1] = $2
    split($3, deplist, " ")
    for (pkg in deplist)
	{
	dep = deplist[pkg]
	sub("-[0-9].*", "", dep) # Strip version
	covered[dep] = 1
	}
    }
    END {
    for (pkg in pkg2dir)
	{
	chk = pkg
	sub("-[0-9].*", "", chk); # Strip version
	if (!covered[chk])
	    print pkg" "pkg2dir[pkg]
	}
    }
    '`
fi

if [ -n "$opt_f" ] ; then
    pkg_fetchlist $UPDATE_FETCH_TODO
    pkg_fetchlist $MISSING_TODO
fi
if [ -n "$opt_u" ] ; then
    pkg_installlist Update  $UPDATE_TODO
fi
if [ -n "$opt_a" ] ; then
    pkg_installlist Install $MISSING_TODO
fi

if [ -n "$UPDATE_DONE" ];then
    echo "Updated:$UPDATE_DONE"
fi
if [ -n "$INSTALL_DONE" ];then
    echo "Installed:$INSTALL_DONE"
fi
if [ -n "$FAIL_DONE" ];then
    echo "Failed:$FAIL_DONE"
fi
