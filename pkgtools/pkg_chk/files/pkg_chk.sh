#!@SH@ -e
#
# $Id: pkg_chk.sh,v 1.21 2005/10/02 02:05:29 heas Exp $
#
# TODO: Make -g check dependencies and tsort
# TODO: Variation of -g which only lists top level packages
# TODO: List top level packages installed but not in config
# TODO: Generate list files so -u can work against a remote URL

PATH=/usr/sbin:/usr/bin:${PATH}

check_packages_installed()
    {
    MISSING_TODO=
    MISMATCH_TODO=

    for pkgdir in $* ; do

	if [ -n "$opt_B" ];then
	    extract_pkg_vars $pkgdir PKGNAME FILESDIR PKGDIR DISTINFO_FILE PATCHDIR
	else
	    extract_pkg_vars $pkgdir PKGNAME
	fi
	if [ -z "$PKGNAME" ]; then
	    MISS_DONE=$MISS_DONE" "$pkgdir
	    continue
	fi
	if [ ! -d $PKG_DBDIR/$PKGNAME ];then
	    msg_n "$PKGNAME: "
	    pkg=$(echo $PKGNAME | ${SED} 's/-[0-9].*//')
	    pkginstalled=$(sh -c "${PKG_INFO} -e $pkg" || true)
	    INSTALL=
	    if [ -n "$pkginstalled" ];then
		msg_n "version mismatch - $pkginstalled"
		MISMATCH_TODO="$MISMATCH_TODO $pkginstalled"
	    else
		msg_n "missing"
		MISSING_TODO="$MISSING_TODO $PKGNAME $pkgdir"
	    fi
	    if [ -f $PACKAGES/$PKGNAME.tgz ] ;then
		msg_n " (binary package available)"
	    fi
	    msg
	else
	    if [ -n "$opt_B" ];then
		current_build_ver=$(get_build_ver)
		installed_build_ver=$(${SED} "s|^[^:]*/[^:]*:||" $PKG_DBDIR/$PKGNAME/+BUILD_VERSION)
		if [ x"$current_build_ver" != x"$installed_build_ver" ];then
		    msg "$PKGNAME: build-version mismatch"
		    verbose "--current--"
		    verbose "$current_build_ver"
		    verbose "--installed--"
		    verbose "$installed_build_ver"
		    verbose "----"
		    MISMATCH_TODO="$MISMATCH_TODO $PKGNAME"
		else
		    verbose "$PKGNAME: OK"
		fi
	    else
		verbose "$PKGNAME: OK"
	    fi
	fi
    done
    }

delete_pkgs()
    {
    for pkg in $* ; do
	if [ -d $PKG_DBDIR/$pkg ] ; then
	    run_cmd "${PKG_DELETE} -r $pkg" 1
	fi
    done
    }

extract_make_vars()
    {
    MAKEFILE=$1
    shift
    verbose "Extract $@ from $MAKEFILE"
    MAKEDATA=".PHONY: x\nx:\n";
    for var in $* ; do
	MAKEDATA=$MAKEDATA"\t@echo $var=\${$var}\n"
    done
    eval $(printf "$MAKEDATA" | ${MAKE} -f - -f $MAKEFILE x | \
					${SED} -e 's/[^=]*=/&"/' -e 's/$/"/')
    }

# $1 = name of variable
# $2 = default value
extract_mk_var()
    {
    if [ -z "`eval echo \\$$1`" ] ; then
	eval $(printf "BSD_PKG_MK=1\n.PHONY: x\nx:\n\t@echo $1="'$'"{$1}\n" | ${MAKE} -f - -f $MAKECONF x)
	if [ -z "`eval echo \\$$1`" ]; then
	    eval "$1=$2"
	fi
    fi
    }

extract_pkg_vars()
    {
    PKGDIR=$1
    PKGNAME=
    shift;
    if [ -n "$opt_b" -a -z "$opt_s" ] ; then
	for pkg in $PKGDB ; do
	    case $pkg in
		"$PKGDIR:"*)
		    PKGNAME=`echo $pkg| ${SED} 's/[^:]*://'`
		    return;
		;;
	    esac
	done
	msg "WARNING: No binary package for $PKGDIR"
    else
	if [ ! -f $PKGSRCDIR/$pkgdir/Makefile ];then
	    msg "WARNING: No $pkgdir/Makefile - package moved or obsolete?"
	    return
	fi
	cd $PKGSRCDIR/$PKGDIR
	extract_make_vars Makefile "$@"
	if [ -z "$PKGNAME" ]; then
	    fatal "Unable to extract PKGNAME for $pkgdir"
	fi
    fi
    }

extract_variables()
    {
    extract_mk_var PKGSRCDIR /usr/pkgsrc
    if [ ! -d $PKGSRCDIR -a ! $opt_b ] ; then
	fatal "Unable to locate PKGSRCDIR ($PKGSRCDIR)"
    fi
    extract_mk_var PKG_DBDIR /var/db/pkg
    if [ ! -d $PKG_DBDIR ] ; then
	fatal "Unable to locate PKG_DBDIR ($PKG_DBDIR)"
    fi

    # Now we have PKGSRCDIR, use it to determine PACKAGES, and PKGCHK_CONF
    # as well as AWK, GREP, SED, PKGCHK_TAGS and PKGCHK_NOTAGS
    #

    if [ -z "$opt_b" -o -n "$opt_s" -o -d $PKGSRCDIR/pkgtools/pkg_chk ] ; then
	cd $PKGSRCDIR/pkgtools/pkg_chk
	extract_make_vars Makefile AWK GREP SED TSORT SORT PACKAGES PKG_INFO \
			PKG_ADD PKG_DELETE PKGCHK_CONF PKGCHK_UPDATE_CONF \
			PKGCHK_TAGS PKGCHK_NOTAGS
	if [ -z "$PACKAGES" ];then
	    PACKAGES=$PKGSRCDIR/packages
	fi
    elif [ $MAKECONF != /dev/null ] ; then
	extract_make_vars $MAKECONF PACKAGES PKGCHK_CONF PKGCHK_UPDATE_CONF \
			PKGCHK_TAGS PKGCHK_NOTAGS
	if [ -z "$PACKAGES" ] ; then
	    PACKAGES=`pwd`
	fi
    fi

    if [ -z "$PKGCHK_CONF" ];then
	PKGCHK_CONF=$PKGSRCDIR/pkgchk.conf
    fi
    if [ -z "$PKGCHK_UPDATE_CONF" ];then
	PKGCHK_UPDATE_CONF=$PKGSRCDIR/pkgchk_update-$(hostname).conf
    fi
    }

fatal()
    {
    msg "*** $@"
    exit 1
    }

fatal_maybe()
    {
    msg "$@"
    if [ -z "$opt_k" ];then
	exit 1
    fi
    }

generate_conf_from_installed()
    {
    FILE=$1
    if [ -r $FILE ]; then
	mv $FILE ${FILE}.old
    fi
    echo "# Generated automatically at $(date)" > $FILE
    echo $(pkgdirs_from_installed) | fmt -1 	>> $FILE
    }

get_build_ver()
    {
    if [ -n "$opt_b" -a -z "$opt_s" ] ; then
	${PKG_INFO} -. -b $PACKAGES/$PKGNAME.tgz | tail +4 | ${SED} "s|^[^:]*/[^:]*:||" | ${GREP} .
	return
    fi
    files=""
    for f in Makefile ${FILESDIR}/* ${PKGDIR}/*; do
	if [ -f $f ];then
	    files="$files $f"
	fi
    done
    if [ -f ${DISTINFO_FILE} ]; then
	for f in $(${AWK} 'NF == 4 && $3 == "=" { gsub("[()]", "", $2); print $2 }' < ${DISTINFO_FILE}); do 
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

list_packages()
    {
    CHECKLIST=' '
    for pkgdir in $* ; do
	extract_pkg_vars $pkgdir PKGNAME
	if [ -z "$PKGNAME" ]; then
	    continue
	fi
	if [ ! -f $PACKAGES/$PKGNAME.tgz ] ;then
	    fatal_maybe " ** $PKGNAME - binary package missing"
	    continue
	fi
	verbose "$PKGNAME.tgz: found"
	CHECKLIST="$CHECKLIST$PKGNAME ";
    done

    PAIRLIST=
    PKGLIST=' '
    while [ "$CHECKLIST" != ' ' ]; do
	NEXTCHECK=' '
	for pkg in $CHECKLIST ; do
	    if [ ! -f $PACKAGES/$pkg.tgz ] ; then
		fatal_maybe " ** $pkg.tgz - binary package dependency missing"
		continue
	    fi
	    DEPLIST="$(${PKG_INFO} -. -N $PACKAGES/$pkg.tgz | ${SED} '1,/Built using:/d' | ${GREP} .. || true)"
	    if [ -z "$DEPLIST" ] ; then
		PAIRLIST="${PAIRLIST}$pkg.tgz $pkg.tgz\n"
	    fi
	    for dep in $DEPLIST ; do
		if [ ! -f $PACKAGES/$dep.tgz ] ; then
		    fatal_maybe " ** $dep.tgz - dependency missing for $pkg"
		    break 2
		fi
		PAIRLIST="${PAIRLIST}$dep.tgz $pkg.tgz\n"
		case "$PKGLIST$CHECKLIST$NEXTCHECK" in
		    *" $dep "*)
			verbose "$pkg: Duplicate depend $dep"
			;;
		    *)
			NEXTCHECK=" $dep$NEXTCHECK"
			verbose "$pkg: Add depend $dep"
			;;
		esac
	    done
	    PKGLIST="$pkg $PKGLIST"
	done
	CHECKLIST="$NEXTCHECK"
    done
    printf "$PAIRLIST" | ${TSORT}
    }

pkgdirs_from_conf()
    {
    CONF=$1; shift
    LIST="$*"
    if [ ! -r $CONF ];then
	fatal "Unable to read PKGCHK_CONF '$CONF'"
    fi

    # Determine list of tags
    #
    if [ $PKGSRCDIR = NONE ]; then
	OPSYS=$(uname -s)
	OS_VERSION=$(uname -r)
	MACHINE_ARCH=$(uname -p)
    else
	extract_make_vars Makefile OPSYS OS_VERSION MACHINE_ARCH
    fi

    TAGS="$(hostname | ${SED} -e 's,\..*,,'),$(hostname),$OPSYS-$OS_VERSION-$MACHINE_ARCH,$OPSYS-$OS_VERSION,$OPSYS-$MACHINE_ARCH,$OPSYS,$OS_VERSION,$MACHINE_ARCH"
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
    verbose "set   TAGS=$TAGS"
    verbose "unset TAGS=$opt_U"

    # Extract list of valid pkgdirs (skip any 'alreadyset' in $LIST)
    #
    LIST="$LIST "$(${AWK} -v alreadyset="$LIST" -v setlist=$TAGS -v unsetlist=$opt_U '
    BEGIN {
	split(alreadyset, tmp, " ");
	for (tag in tmp) { skip[tmp[tag]] = 1; }

	split(setlist, tmp, ",");
	for (tag in tmp) { taglist[tmp[tag]] = 1; }

	split(unsetlist, tmp, ",");
	for (tag in tmp) { skip[tmp[tag]] = 1; delete taglist[tmp[tag]] }

	taglist["*"] = "*"
    }
    function and_expr_with_dict(expr, dict, ary, i, r, d) {
	split(expr,ary,/\+/);
	r = 1;
	for (i in ary) {
		if (ary[i] ~ /^\//) {
			if (getline d < ary[i] == -1)
			    { r = 0; break ;}
		}
		else if (! (ary[i] in dict))
			{ r = 0; break ;}
	}
	return r;
    }
    {
    sub("#.*", "");
    if (skip[$1])
	next;
    need = 0;
    if ($0 ~ /\=/) {
	split($0, tmp, "[ \t]*=");
	taggroup = tmp[1];
	sub("[ \t]*=", "=");
	}
    else
	{
	taggroup = ""
	if (NF == 1)			# If only one arg, we want pkg
	    need = 1;
	}
    for (f = 2 ; f<=NF ; ++f) {		# For each word on the line
	if (sub("^-", "", $f)) { 	# If it begins with a '-'
		if (f == 2)		# If first entry '-', assume '*'
		    { need = 1; }
		if (and_expr_with_dict($f, taglist))
			next;		# If it is true, discard
	} else {
		if (and_expr_with_dict($f, taglist))
			need = 1;	# If it is true, note needed
	}
    }
    if (need)
	if (taggroup)
	    taglist[taggroup] = 1
	else
	    print $1;
    }
    ' < $CONF
    )
    echo $LIST
    }

pkgdirs_from_installed()
    {
    ${PKG_INFO} -Bqa | ${AWK} -F= '/PKGPATH=/{print $2}' | ${SORT}
    }

msg()
    {
    if [ -n "$opt_L" ] ; then
	echo "$@" >> "$opt_L"
    fi
    if [ -n "$opt_l" ] ; then
	echo "$@" >&2
    else
	echo "$@"
    fi
    }

msg_progress()
    {
    msg "[ $@ ]"
    }

msg_n()
    {
    msg $ac_n "$*"$ac_c
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

pkg_fetchlist()
    {
    PKGLIST=$@
    msg_progress Fetch
    while [ $# != 0 ]; do 
	pkg_fetch $1 $2
	shift ; shift;
    done
    }

pkg_install()
    {
    PKGNAME=$1
    PKGDIR=$2
    INSTALL=$3

    if [ -d $PKG_DBDIR/$PKGNAME ];then
	msg "$PKGNAME installed in previous stage"
    elif [ -n "$opt_b" -a -f $PACKAGES/$PKGNAME.tgz ] ; then
	if [ -n "$saved_PKG_PATH" ] ; then
	    export PKG_PATH=$saved_PKG_PATH
	fi
	cd $PACKAGES
	run_cmd "${PKG_ADD} $PKGNAME.tgz"
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
    else
	INSTALL_DONE=$INSTALL_DONE" "$PKGNAME
    fi
    }

pkg_installlist()
    {
    INSTALL=$1 ; shift
    msg_progress $INSTALL
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
    msg $(date +%R) $1
    if [ -z "$opt_n" ];then
	if [ -n "$opt_L" ] ; then
	    sh -c "$1" >> "$opt_L" 2>&1 || FAIL=1
	else
	    sh -c "$1" || FAIL=1
	fi
	if [ -n "$FAIL" ] ; then
            msg "** '$1' failed"
	    if [ -n "$opt_L" ] ; then
		tail -100 "$opt_L" | egrep -v '^(\*\*\* Error code 1|Stop\.)' |\
			tail -40
	    fi
            if [ "$FAILOK" != 1 ]; then
                exit 1
            fi
        fi
    fi
    }

set_path()
    {
    arg=$1
    case $arg in
	/*)	echo $arg ;;
	*)	echo $basedir/$arg ;;
    esac
    }

usage()
    {
    if [ -n "$1" ] ; then
	echo "$@"
	echo
    fi
    echo 'Usage: pkg_chk [opts]
	-a      Add all missing packages (implies -c)
	-B      Check the "Build version" of packages
	-b      Install binary packages
	-C conf Use pkgchk.conf file 'conf'
	-c      Check installed packages against pkgchk.conf
	-D tags Comma separated list of additional pkgchk.conf tags to set
	-f      Perform a 'make fetch' for all required packages
	-g      Generate an initial pkgchk.conf file
	-h      This help
	-i	Check versions of installed packages (not using pkgchk.conf)
	-k	Continue with further packages if errors are encountered
	-L file Redirect output from commands run into file (should be fullpath)
	-l	List binary packages including dependencies (implies -c)
	-N	List installed packages for which a newer version is in TODO
	-n	Display actions that would be taken, but do not perform them
	-P dir  Set PACKAGES dir (overrides any other setting)
	-r	Recursively remove mismatches (use with care) (implies -i)
	-s      Install packages by building from source
	-U tags Comma separated list of pkgchk.conf tags to unset
	-u      Update all mismatched packages (implies -i)
	-v      Verbose

pkg_chk verifies installed packages against pkgsrc.
The most common usage is 'pkg_chk -i' to check all installed packages or
'pkg_chk -u' to update all out of date packages.
For more advanced usage, including defining a set of desired packages based
on hostname and type, see pkg_chk(8).

If neither -b nor -s is given, both are assumed with -b preferred.
'
    exit 1
    }

verbose()
    {
    if [ -n "$opt_v" ] ; then
	msg "$@" >&2
    fi
    }

args=$(getopt BC:D:L:P:U:abcfghiklNnrsuv $*)
if [ $? != 0 ]; then
    opt_h=1
fi
set -- $args
while [ $# != 0 ]; do
    case "$1" in
	-a )	opt_a=1 ; opt_c=1 ;;
	-B )    opt_B=1 ;;
	-b )	opt_b=1 ;;
	-C )	opt_C="$2" ; shift;;
	-c )	opt_c=1 ;;
	-D )	opt_D="$2" ; shift;;
	-f )	opt_f=1 ;;
	-g )	opt_g=1 ;;
	-h )	opt_h=1 ;;
	-i )	opt_i=1 ;;
	-k )	opt_k=1 ;;
	-L )	opt_L="$2" ; shift;;
	-l )	opt_l=1 ;;
	-N )	opt_N=1 ;;
	-n )	opt_n=1 ;;
	-P )	opt_P="$2" ; shift;;
	-r )	opt_r=1 ; opt_i=1 ;;
	-s )	opt_s=1 ;;
	-U )	opt_U="$2" ; shift;;
	-u )	opt_u=1 ; opt_i=1 ;;
	-v )	opt_v=1 ;;
	-- )	shift; break ;;
    esac
    shift
done

if [ -z "$opt_b" -a -z "$opt_s" ];then
    opt_b=1; opt_s=1;
fi

if [ -z "$opt_a" -a -z "$opt_c" -a -z "$opt_g" -a -z "$opt_i" -a -z "$opt_N" -a -z "$opt_l" ];
then
    usage "Must specify at least one of -a, -c, -g, -i, -l, -N, or -u";
fi

if [ -n "$opt_h" -o $# != 0 ];then
    usage
fi

# Hide PKG_PATH to avoid breakage in 'make' calls
saved_PKG_PATH=$PKG_PATH
unset PKG_PATH || true

test -n "$AWK"        || AWK="@AWK@"
test -n "$GREP"       || GREP="@GREP@"
test -n "$MAKE"       || MAKE="@MAKE@"
test -n "$MAKECONF"   || MAKECONF="@MAKECONF@"
test -n "$PKG_ADD"    || PKG_ADD="@PKG_ADD@"
test -n "$PKG_DELETE" || PKG_DELETE="@PKG_DELETE@"
test -n "$PKG_INFO"   || PKG_INFO="@PKG_INFO@"
test -n "$SED"        || SED="@SED@"
test -n "$SORT"	      || SORT="@SORT@"
test -n "$TSORT"      || TSORT="@TSORT@"

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
  if (echo -n testing; echo 1,2,3) | ${SED} s/-n/xn/ | grep xn >/dev/null; then
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

basedir=$(pwd)
extract_variables
if [ -n "$opt_C" ] ; then
    PKGCHK_CONF="$(set_path $opt_C)"
fi
if [ -n "$opt_P" ] ; then
    PACKAGES="$(set_path $opt_P)"
fi
if [ -d $PACKAGES/All ] ; then
    PACKAGES="$PACKAGES/All"
fi

if [ -n "$opt_N" ]; then
	${PKG_INFO} | \
		${SED} -e "s/[ 	].*//" -e "s/-[^-]*$//" \
		       -e "s/py[0-9][0-9]pth-/py-/" \
		       -e "s/py[0-9][0-9]-/py-/" | \
		while read a
		do
			b=$(grep "o $a-[0-9]" $PKGSRCDIR/doc/TODO | \
				sed -e "s/[ 	]*o //")
		if [ "$b" ]
		then
			echo $a: $b
		fi
	done
fi

if [ -n "$opt_b" -a -z "$opt_s" -a -d $PACKAGES ] ; then
    msg_progress Scan $PACKAGES
    cd $PACKAGES
    for f in `ls -t *.tgz` ; do # Sort by time to pick up newest first
	PKGDIR=`${PKG_INFO} -. -B $PACKAGES/$f|${AWK} -F= '$1=="PKGPATH"{print $2}'`
	PKGNAME=`echo $f | ${SED} 's/\.tgz$//'`
	PKGDB="${PKGDB} $PKGDIR:$PKGNAME"
    done
    PKGSRCDIR=NONE
fi

if [ -n "$opt_g" ]; then
    verbose "Write $PKGCHK_CONF based on installed packages"
    generate_conf_from_installed $PKGCHK_CONF
fi

if [ -n "$opt_i" ];then
    verbose "Enumerate PKGDIRLIST from installed packages"
    PKGDIRLIST=$(pkgdirs_from_installed)
fi

if [ -n "$opt_c" -o -n "$opt_l" ];then	# Append to PKGDIRLIST based on conf
    verbose "Append to PKGDIRLIST based on config $PKGCHK_CONF"
    PKGDIRLIST="$(pkgdirs_from_conf $PKGCHK_CONF $PKGDIRLIST)"
fi

if [ -n "$opt_l" ] ; then
    list_packages $PKGDIRLIST
else
    check_packages_installed $PKGDIRLIST
fi

if [ -n "$MISMATCH_TODO" ]; then
    delete_and_recheck=1
elif [ -n "$opt_u" -a -f $PKGCHK_UPDATE_CONF ] ; then
    delete_and_recheck=1
fi

if [ -n "$delete_and_recheck" ]; then
    if [ -n "$opt_u" ] ; then		 # Save current installed list
	if [ -f $PKGCHK_UPDATE_CONF ] ; then
	    msg "Merging in previous $PKGCHK_UPDATE_CONF"
	    tmp=$(cat $PKGCHK_UPDATE_CONF;echo $(pkgdirs_from_installed)|fmt -1)
	    echo $tmp | fmt -1 | ${SORT} -u > $PKGCHK_UPDATE_CONF
	    tmp=
	else
	    echo $(pkgdirs_from_installed) | fmt -1 > $PKGCHK_UPDATE_CONF
	fi
    fi
    if [ -n "$opt_r" -o -n "$opt_u" ] ; then
	if [ -n "$MISMATCH_TODO" ]; then
	    delete_pkgs $MISMATCH_TODO
	    msg_progress Rechecking packages after deletions
	fi
	if [ -n "$opt_u" ]; then
	    PKGDIRLIST="$(pkgdirs_from_conf $PKGCHK_UPDATE_CONF $PKGDIRLIST)"
	fi
	if [ -n "$opt_u" -o -n "$opt_a" ]; then
	    check_packages_installed $PKGDIRLIST # May need to add more
	fi
    fi
fi

if [ -n "$opt_f" ] ; then
    pkg_fetchlist $MISSING_TODO
fi

if [ -n "$MISSING_TODO" ] ; then
    if [ -n "$opt_a" -o -n "$opt_u" ] ; then
	pkg_installlist Install $MISSING_TODO
    fi
fi

if [ -n "$opt_u" -a -z "$FAIL_DONE" -a -f $PKGCHK_UPDATE_CONF ] ; then
    run_cmd "rm -f $PKGCHK_UPDATE_CONF"
fi

[ -n "$MISS_DONE" ] &&		msg "Missing:$MISS_DONE"
[ -n "$INSTALL_DONE" ] &&	msg "Installed:$INSTALL_DONE"
[ -n "$FAIL_DONE" ] &&		msg "Failed:$FAIL_DONE"

[ -z "$FAIL_DONE" ]
