#!/bin/sh -e
#
# $Id: pkgchk.sh,v 1.24 2001/12/24 14:15:56 abs Exp $
#
# TODO: Handle updates with dependencies via binary packages

PATH=/usr/sbin:${PATH}

check_packages_installed()
    {
    UPDATE_TODO=
    INSTALL_TODO=
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
	if [ ! -d /var/db/pkg/$PKGNAME ];then
	    echo_n "$PKGNAME: "
	    pkg=`echo $PKGNAME | sed 's/-[0-9].*//'`
	    pkginstalled=`pkg_info -e $pkg || true`
	    INSTALL=
	    if [ -n "$pkginstalled" ];then
		echo_n "version mismatch - $pkginstalled"
		MISMATCH_TODO="$MISMATCH_TODO $pkginstalled"
		if [ -n "$opt_u" ]; then
		    UPDATE_TODO="$UPDATE_TODO $PKGNAME $pkgdir"
		fi
	    else
		echo_n "missing"
		if [ -n "$opt_a" ] ; then
		    INSTALL_TODO="$INSTALL_TODO $PKGNAME $pkgdir"
		fi
	    fi
	    if [ -f $PACKAGES/All/$PKGNAME.tgz ] ;then
		echo_n " (binary package available)"
	    fi
	    echo
	else
	    if [ -n "$opt_B" ];then
		current_build_ver=`get_build_ver`
		installed_build_ver=`cat /var/db/pkg/$PKGNAME/+BUILD_VERSION | sed "s:^${real_pkgsrcdir}/::"`
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
    MAKEDATA="x:\n";
    for var in $* ; do
	MAKEDATA=$MAKEDATA"\t@echo $var=\${$var}\n"
    done
    eval `printf "$MAKEDATA" | ${MAKE} -f - -f Makefile x`
    }

extract_variables()
    {
    # Establish PKGSRCDIR
    #

    if [ -z "$PKGSRCDIR" ];then
	if [ -f /etc/mk.conf ] ;then
	    eval `printf 'BSD_PKG_MK=1\nx:\n\t@echo PKGSRCDIR=${PKGSRCDIR}\n' | ${MAKE} -f - -f /etc/mk.conf x` 
	fi
	if [ -z "$PKGSRCDIR" ];then
	    PKGSRCDIR=/usr/pkgsrc
	fi
    fi
    if [ ! -d $PKGSRCDIR ];then
	echo "Unable to locate PKGSRCDIR '$PKGSRCDIR'"
	exit 1;
    fi

    # Now we have PKGSRCDIR, use it to determine PACKAGES, and PKGCHK_CONF
    # as well as AWK, GREP, SED, PKGCHK_TAGS and PKGCHK_NOTAGS
    #

    cd $PKGSRCDIR/pkgtools/pkgchk
    extract_make_vars AWK GREP SED PACKAGES PKGCHK_CONF PKGCHK_TAGS PKGCHK_NOTAGS

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
    for f in `pwd`/Makefile ${FILESDIR}/* ${PKGDIR}/*; do
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
    ${GREP} '\$NetBSD' $files | ${SED} -e "s|^${real_pkgsrcdir}/||"
    }

pkg_install()
    {
    PKGNAME=$1
    PKGDIR=$2
    INSTALL=$3

    if [ -d /var/db/pkg/$PKGNAME ];then
	echo "$PKGNAME installed in previous stage"
    elif [ -n "$opt_b" -a -f $PACKAGES/All/$PKGNAME.tgz ] ; then
	if [ $INSTALL = U ];then
	    PKG=`echo $PKGNAME | sed 's/-[0-9].*//'`
	    run_cmd "pkg_delete $PKG" 1
	    if [ -n "$FAIL" ]; then
		echo "Can only update packages with dependencies via -s"
		exit 1
	    fi
	fi
	run_cmd "pkg_add $PACKAGES/All/$PKGNAME.tgz"
    elif [ -n "$opt_s" ]; then
	run_cmd "cd $PKGSRCDIR/$PKGDIR && ${MAKE} update"
    fi

    if [ -z "$opt_n" -a ! -d /var/db/pkg/$PKGNAME ];then
	FAIL=1
    fi

    if [ -n "$FAIL" ]; then
	FAIL_DONE=$FAIL_DONE" "$PKGNAME
    elif [ $INSTALL = U ];then
	UPDATE_DONE=$UPDATE_DONE" "$PKGNAME
    else
	INSTALL_DONE=$INSTALL_DONE" "$PKGNAME
    fi
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
        sh -c "$1" || FAIL=1
	if [ -n "$FAIL" ] ; then
            echo "** '$1' failed"
            if [ "$FAILOK" != 1 ]; then
                exit 1
            fi
        fi
    fi
    }

args=`getopt BC:D:U:abchiknrsuv $*`
if [ $? != 0 ]; then
    opt_h=1
fi
set -- $args
while [ $# != 0 ]; do
    case "$1" in
	-B )    opt_B=1 ; opt_i=1 ;;
	-C )	opt_C="$2" ; shift;;
	-D )	opt_D="$2" ; shift;;
	-U )	opt_U="$2" ; shift;;
	-a )	opt_a=1 ; opt_c=1 ;;
	-b )	opt_b=1 ;;
	-c )	opt_c=1 ;;
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
	-U tags Comma separated list of pkgchk.conf tags to unset
	-a      Add all missing packages (implies -c)
	-b      Limit installations to binary packages
	-c      Check installed packages against pkgchk.conf
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

test -n "$MAKE" || MAKE="@MAKE@"

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

extract_variables
if [ -n "$opt_C" ] ; then
    PKGCHK_CONF=$opt_C
fi

cd $PKGSRCDIR
real_pkgsrcdir=`pwd`

if [ -n "$opt_i" ];then
    PKGDIRLIST=`pkg_info -B \* | ${AWK} '/PKGPATH= /{print $2}'`
fi

if [ -n "$opt_c" ];then

    if [ ! -r $PKGCHK_CONF ];then
	echo "Unable to read PKGCHK_CONF '$PKGCHK_CONF'"
	exit 1;
    fi

    # Determine list of tags
    #
    TAGS="`hostname | sed -e 's,\..*,,'`,`uname -srm | ${AWK} '{print $1"-"$2"-"$3","$1"-"$2","$1"-"$3","$1","$2","$3}'`"
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
    run_cmd "pkg_delete -r $MISMATCH_TODO"
    if [ -n "$opt_a" ] ; then
	echo "[ Rechecking packages after deletions ]"
	check_packages_installed $PKGDIRLIST # May need to add more packages
    fi
fi

if [ -n "$UPDATE_TODO" ];then
    echo "[ Update... ]"

    # Generate list including packages which depend on updates
    #
    set -- $UPDATE_TODO
    while [ $# != 0 ]; do
	PKGNAME=`echo $1 | sed 's/-[0-9].*//'`
	if [ -f /var/db/pkg/$PKGNAME-[0-9]*/+REQUIRED_BY ];then
	    LIST="$LIST$1|$2|`cat /var/db/pkg/$PKGNAME-[0-9]*/+REQUIRED_BY | xargs echo`\n"
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

    set -- $UPDATE_TODO
    while [ $# != 0 ]; do
	pkg_install $1 $2 U
	shift ; shift;
    done
fi

if [ -n "$INSTALL_TODO" ];then
    echo ""
    echo "[ Install... ]"
    set -- $INSTALL_TODO
    while [ $# != 0 ]; do
	pkg_install $1 $2 I
	shift ; shift;
    done
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
