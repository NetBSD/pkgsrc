#!@SH@ -e
#
# $Id: pkg_chk.sh,v 1.53 2008/02/17 00:55:21 tnn Exp $
#
# TODO: Make -g check dependencies and tsort
# TODO: Variation of -g which only lists top level packages
# TODO: List top level packages installed but not in config

PATH=${PATH}:/usr/sbin:/usr/bin

SUMMARY_FILE=pkg_summary.gz
OLD_SUMMARY_FILE=pkg_chk-summary

is_binary_available()
    {
    if [ -n "$PKGDB" ]; then
	for iba_pkg in $PKGDB; do
	    case $iba_pkg in
		*:"$1")
		    return 0;
		;;
	    esac
        done
	return 1;
    else
	if [ -f "$PACKAGES/$1$PKG_SUFX" ]; then
	    return 0;
	else
	    return 1;
	fi
    fi
    }

bin_pkg_info2pkgdb()
    {
    ${AWK} '/^PKGNAME=/ {sub("^PKGNAME=", ""); PKGNAME=$0} \
            /^PKGPATH=/ {sub("^PKGPATH=", ""); printf("%s:%s ", $0, PKGNAME)}'
    }

check_packages_installed()
    {
    MISSING_TODO=
    MISMATCH_TODO=

    for pkgdir in $* ; do

	if [ -n "$opt_B" ];then
	    extract_pkg_vars $pkgdir PKGNAME FILESDIR PKGDIR DISTINFO_FILE PATCHDIR
	elif [ -n "$opt_s" ] ; then
	    extract_pkg_vars $pkgdir PKGNAME
	else
	    PKGNAME=`pkgdir2pkgname $pkgdir`
	fi
	if [ -z "$PKGNAME" ]; then
	    MISS_DONE=$MISS_DONE" "$pkgdir
	    continue
	fi
	if [ ! -d $PKG_DBDIR/$PKGNAME ];then
	    msg_n "$pkgdir - "
	    pkg=$(echo $PKGNAME | ${SED} 's/-[0-9].*//')
	    pkginstalled=$(sh -c "${PKG_INFO} -e $pkg" || true)
	    INSTALL=
	    if [ -n "$pkginstalled" ];then
		msg_n "$pkginstalled < $PKGNAME"
		MISMATCH_TODO="$MISMATCH_TODO $pkginstalled"
	    else
		msg_n "$PKGNAME missing"
		MISSING_TODO="$MISSING_TODO $PKGNAME $pkgdir"
	    fi
	    if is_binary_available $PKGNAME ;then
		msg_n " (binary package available)"
	    fi
	    msg
	else
	    if [ -n "$opt_B" ];then
		# sort here temporarily to handle older +BUILD_VERSION
		current_build_ver=$(get_build_ver | ${SED} 's|.*\$Net''BSD\: ||' | ${SORT} -u)
		installed_build_ver=$(${SED} 's|.*\$Net''BSD\: ||' $PKG_DBDIR/$PKGNAME/+BUILD_VERSION | ${SORT} -u)
		if [ x"$current_build_ver" != x"$installed_build_ver" ];then
		    msg "$pkgdir - $PKGNAME build_version mismatch"
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

cleanup_and_exit()
    {
    rm -f $MY_TMPFILE
    rmdir $MY_TMPDIR
    exit "$@"
    }

delete_pkgs()
    {
    for pkg in $* ; do
	if [ -d $PKG_DBDIR/$pkg ] ; then
	    run_cmd_su "${PKG_DELETE} -r $pkg" 1
	fi
    done
    }

extract_make_vars()
    {
    MAKEFILE=$1
    shift
    MAKEDATA=".PHONY: x\nx:\n";
    for var in $* ; do
	MAKEDATA=$MAKEDATA"\t@echo $var=\${$var}\n"
    done
    eval $(printf "$MAKEDATA" | ${MAKE} -f - -f $MAKEFILE x | \
					${SED} -e 's/[^=]*=/&"/' -e 's/$/"/')
    for var in $* ; do
	verbose_var $var
    done
    }

# $1 = name of variable
# $2 = default value
extract_mk_var()
    {
    if [ -z "`eval echo \\$$1`" ] ; then
	eval $(printf "BSD_PKG_MK=1\n.PHONY: x\nx:\n\t@echo $1="'$'"{$1}\n" | ${MAKE} -f - -f $MAKECONF x)
	if [ -z "`eval echo \\$$1`" ]; then
	    eval "$1=$2"
	    verbose_var $1 '(using default)'
	else
	    verbose_var $1
	fi
    fi
    }

extract_pkg_vars()
    {
    PKGDIR=$1
    PKGNAME=
    shift;
    if [ ! -f $PKGSRCDIR/$pkgdir/Makefile ];then
	msg "WARNING: No $pkgdir/Makefile - package moved or obsolete?"
	return
    fi
    cd $PKGSRCDIR/$PKGDIR
    extract_make_vars Makefile "$@"
    if [ -z "$PKGNAME" ]; then
	fatal "Unable to extract PKGNAME for $pkgdir"
    fi
    }

extract_variables()
    {
    extract_mk_var PKGSRCDIR /usr/pkgsrc
    if [ ! -d $PKGSRCDIR -a -z "$opt_b" ] ; then
	fatal "Unable to locate PKGSRCDIR ($PKGSRCDIR)"
    fi

    # Now we have PKGSRCDIR, use it to determine PACKAGES, and PKGCHK_CONF
    # as well as AWK, GREP, SED, PKGCHK_TAGS and PKGCHK_NOTAGS
    #

    if [ -n "$opt_g" ]; then
        :
    elif [ -z "$opt_b" -o -n "$opt_s" -o -d $PKGSRCDIR/pkgtools/pkg_chk ] ; then
	cd $PKGSRCDIR/pkgtools/pkg_chk
	extract_make_vars Makefile \
		AWK GREP GZIP_CMD ID PACKAGES PKGCHK_CONF PKGCHK_NOTAGS \
		PKGCHK_TAGS PKGCHK_UPDATE_CONF PKG_ADD PKG_DBDIR PKG_DELETE \
		PKG_ADMIN PKG_INFO PKG_SUFX SED SORT SU_CMD TSORT
	if [ -z "$PACKAGES" ];then
	    PACKAGES=$PKGSRCDIR/packages
	fi
    elif [ $MAKECONF != /dev/null ] ; then
	extract_make_vars $MAKECONF PACKAGES PKGCHK_CONF PKGCHK_UPDATE_CONF \
			PKGCHK_TAGS PKGCHK_NOTAGS PKG_SUFX
	if [ -z "$PACKAGES" ] ; then
	    PACKAGES=`pwd`
	fi
    fi

    # .tgz/.tbz to regexp
    PKG_SUFX_RE=`echo $PKG_SUFX | sed 's/[.]/[.]/'`

    if [ ! -d $PKG_DBDIR ] ; then
	fatal "Unable to access PKG_DBDIR ($PKG_DBDIR)"
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
    msg "*** $@" >&2
    cleanup_and_exit 1
    }

fatal_later()
    {
    msg "*** $@" >&2
    fatal_later=1
    }

fatal_later_check()
    {
    if [ "$fatal_later" = 1 ] ; then
	cleanup_and_exit 1
    fi
    }

fatal_maybe()
    {
    if [ -z "$opt_k" ];then
	fatal "$@"
    else
	msg "$@"
    fi
    }

generate_conf_from_installed()
    {
    FILE=$1
    if [ -r $FILE ]; then
	mv $FILE ${FILE}.old
    fi
    echo "# Generated automatically at $(date)" > $FILE
    echo $(pkgdirs_from_installed) | tr ' ' '\n' >> $FILE
    }

get_bin_pkg_info()
    {
    list_bin_pkgs | ${XARGS} ${PKG_INFO} -X
    }

get_build_ver()
    {
    if [ -n "$opt_b" -a -z "$opt_s" ] ; then
	${PKG_INFO} -. -q -b $PACKAGES/$PKGNAME$PKG_SUFX | ${GREP} .
	return
    fi
    # Unfortunately pkgsrc always outputs to a file, but it does helpfully
    # allows # us to specify the name
    rm -f $MY_TMPFILE
    ${MAKE} _BUILD_VERSION_FILE=$MY_TMPFILE $MY_TMPFILE
    cat $MY_TMPFILE
    }

list_bin_pkgs ()
    {
    ls -t $PACKAGES | grep "$PKG_SUFX_RE"'$' | sed "s|^|$PACKAGES/|"
    }

# Given a binary package filename as the first argumennt, return a list
# of exact package versions against which it was built and on which it
# depends
#
list_dependencies()
    {
    ${PKG_INFO} -. -q -n $1 | ${GREP} .. || true
    }

# Pass a list of pkgdirs, outputs a tsorted list including any dependencies
#
list_packages()
    {
    # Convert passed in list of pkgdirs to a list of binary package files
    pkglist=''
    for pkgdir in $* ; do
	pkgname=`pkgdir2pkgname $pkgdir`
	if [ -z "$pkgname" ]; then
	    fatal_later "$pkgdir - Unable to extract pkgname"
	    continue
	fi
	if is_binary_available $pkgname ; then
	    pkglist="$pkglist $pkgname$PKG_SUFX"
	else
	    fatal_later "$pkgname - no binary package found"
	fi
    done

    # Variables used in this loop:
    # pkglist: Current list of binary package files to check for dependencies
    # next_pkglist: List of binary package files to check after pkglist
    # pairlist: completed list of package + dependency for use in tsort
    while [ -n "$pkglist" ] ; do
	verbose "pkglist: $pkglist"
	for pkg in $pkglist ; do
	    set -o noglob
	    deplist="$(list_dependencies $PACKAGES/$pkg)"
	    verbose "$pkg: dependencies - `echo $deplist`" 
	    if [ -n "$deplist" ] ; then
		for depmatch in $deplist ; do
		    dep=`${PKG_ADMIN} -b -d $PACKAGES lsbest "$depmatch"`
		    if [ -z "$dep" ] ; then
			fatal_later "$depmatch: dependency missing for $pkg"
		    else
			pairlist="$pairlist$dep $pkg\n"
			case $dep_cache in 
			    *" $dep "*)
				# depmatch_cache is a quick cache of already
				verbose "$pkg: $deplist - cached"
				;;
			    *)
				next_pkglist="$next_pkglist $dep"
				dep_cache="$dep_cache $dep "
				;;
			esac
		    fi
		done
	    else
		pairlist="$pairlist$pkg $pkg\n"
	    fi
	    set +o noglob
	done
	pkglist="$next_pkglist"
	next_pkglist=
    done
    if [ -z "$opt_k" ] ; then
	fatal_later_check
    fi
    printf "$pairlist" | ${TSORT}
    }

pkgdir2pkgname()
    {
    pkgdir=$1
    for pkgline in $PKGDB ; do
	case $pkgline in
	    "$pkgdir:"*)
		echo $pkgline | ${SED} 's/[^:]*://'
		return;
	    ;;
	esac
    done
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

    # If '-U' contains a '*' then we need to unset TAGS and PKGCHK_TAGS, but
    # still pick up -D, and even package specific -U options
    verbose "unset TAGS=$opt_U"
    case ",$opt_U," in
	*,\*,*)
	    TAGS=''
	    ;;
    esac
    if [ -n "$TAGS" ];then
	if [ -n "$opt_D" ];then
		opt_D="$opt_D,$TAGS"
	else
		opt_D="$TAGS"
	fi
    fi
    verbose "set   TAGS=$opt_D"

    # Extract list of valid pkgdirs (skip any 'alreadyset' in $LIST)
    #
    LIST="$LIST "$(${AWK} -v alreadyset="$LIST" -v setlist="$opt_D" -v unsetlist="$opt_U" '
    BEGIN {
	split(alreadyset, tmp, " ");
	for (tag in tmp) { skip[tmp[tag]] = 1; }

	split(setlist, tmp, ",");
	for (tag in tmp) { taglist[tmp[tag]] = 1; }

	split(unsetlist, tmp, ",");
	for (tag in tmp) { skip[tmp[tag]] = 1; nofile[tmp[tag]] = 1 ;
			delete taglist[tmp[tag]] }

	taglist["*"] = "*"
    }
    function and_expr_with_dict(expr, dict, ary, i, r, d) {
	split(expr,ary,/\+/);
	r = 1;
	for (i in ary) {
		if (ary[i] ~ /^\// && ! nofile[ary[i]]) {
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
    if [ -z "$opt_q" ] ; then
	msg "[ $@ ]"
    fi
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

    FAIL=
    if [ -d $PKG_DBDIR/$PKGNAME ];then
	msg "$PKGNAME installed in previous stage"
    elif [ -n "$opt_b" ] && is_binary_available $PKGNAME; then
	if [ -n "$saved_PKG_PATH" ] ; then
	    export PKG_PATH=$saved_PKG_PATH
	fi
	run_cmd_su "${PKG_ADD} $PACKAGES/$PKGNAME$PKG_SUFX"
	if [ -n "$saved_PKG_PATH" ] ; then
	    unset PKG_PATH
	fi
    elif [ -n "$opt_s" ]; then
	run_cmd "cd $PKGSRCDIR/$PKGDIR && ${MAKE} update CLEANDEPENDS=yes"
    fi

    if [ -z "$opt_n" -a -z "$opt_q" -a ! -d $PKG_DBDIR/$PKGNAME ];then
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
    if [ -z "$opt_q" ];then
	msg $(date +%R) $1
    fi
    if [ -z "$opt_n" -a -z "$opt_q" ];then
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
                fatal "** '$1' failed"
            fi
        fi
    fi
    }

run_cmd_su()
    {
    if [ -n "$SU_CMD" ]; then
	run_cmd "${SU_CMD} '$1'" "$2"
    else
	run_cmd "$1" "$2"
    fi
    }

set_path()
    {
    arg=$1
    case $arg in
	http://*|ftp://*|/*)
		echo $arg ;;
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
	-b      Use binary packages
	-C conf Use pkgchk.conf file 'conf'
	-D tags Comma separated list of additional pkgchk.conf tags to set
	-f      Perform a 'make fetch' for all required packages
	-g      Generate an initial pkgchk.conf file
	-h      This help
	-k	Continue with further packages if errors are encountered
	-L file Redirect output from commands run into file (should be fullpath)
	-l	List binary packages including dependencies (implies -c)
	-N	List installed packages for which a newer version is in TODO
	-n	Display actions that would be taken, but do not perform them
	-p	Display the list of pkgdirs that match the current tags
	-P dir  Set PACKAGES dir (overrides any other setting)
	-q	Do not display actions or take any action; only list packages
	-r	Recursively remove mismatches (use with care) (implies -i)
	-s      Use source for building packages
	-U tags Comma separated list of pkgchk.conf tags to unset ('*' for all)
	-u      Update all mismatched packages (implies -i)
	-v      Verbose

pkg_chk verifies installed packages against pkgsrc.
The most common usage is 'pkg_chk -u -q' to check all installed packages or
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

verbose_var()
    {
    if [ -n "$opt_v" ] ; then
	var=$1
	shift
	verbose Variable $var = $(eval echo \$$var) $@
    fi
    }

args=$(getopt BC:D:L:P:U:abcfghiklNnpqrsuv "$@")
if [ $? != 0 ]; then
    opt_h=1
fi
set -o noglob # -U can be '*'
set -- $args
set +o noglob
while [ $# != 0 ]; do
    case "$1" in
	-a )	opt_a=1 ;;
	-B )    opt_B=1 ;;
	-b )	opt_b=1 ;;
	-C )	opt_C="$2" ; shift ;;
	-c )	opt_a=1 ; opt_q=1 ; echo "-c is deprecated - use -a -q" ;;
	-D )	opt_D="$2" ; shift ;;
	-f )	opt_f=1 ;;
	-g )	opt_g=1 ;;
	-h )	opt_h=1 ;;
	-i )	opt_u=1 ; opt_q=1 ; echo "-i is deprecated - use -u -q" ;;
	-k )	opt_k=1 ;;
	-L )	opt_L="$2" ; shift ;;
	-l )	opt_l=1 ;;
	-N )	opt_N=1 ;;
	-n )	opt_n=1 ;;
	-p )	opt_p=1 ;;
	-P )	opt_P="$2" ; shift ;;
	-q )	opt_q=1 ;;
	-r )	opt_r=1 ;;
	-s )	opt_s=1 ;;
	-U )	opt_U="$2" ; shift ;;
	-u )	opt_u=1 ;;
	-v )	opt_v=1 ;;
	-- )	shift; break ;;
    esac
    shift
done

if [ -z "$opt_b" -a -z "$opt_s" ];then
    opt_b=1; opt_s=1;
fi

if [ -z "$opt_a$opt_g$opt_l$opt_p$opt_r$opt_u$opt_N" ];
then
    usage "Must specify at least one of -a, -g, -l, -p, -r, -u or -N";
fi

if [ -n "$opt_h" ];then
    usage
fi

if [ $# != 0 ];then
    usage "Additional argument ($*) given"
fi

# Hide PKG_PATH to avoid breakage in 'make' calls
saved_PKG_PATH=$PKG_PATH
unset PKG_PATH || true

test -n "$AWK"        || AWK="@AWK@"
test -n "$GREP"       || GREP="@GREP@"
test -n "$GZIP_CMD"   || GZIP_CMD="@GZIP_CMD@"
export GZIP_CMD
test -n "$ID"         || ID="@ID@"
test -n "$MAKE"       || MAKE="@MAKE@"
test -n "$MAKECONF"   || MAKECONF="@MAKECONF@"
test -n "$MKTEMP"     || MKTEMP="@MKTEMP@"
test -n "$PKG_ADD"    || PKG_ADD="@PKG_ADD@"
test -n "$PKG_ADMIN"  || PKG_ADMIN="@PKG_ADMIN@"
test -n "$PKG_DBDIR"  || PKG_DBDIR="@PKG_DBDIR@"
test -n "$PKG_DELETE" || PKG_DELETE="@PKG_DELETE@"
test -n "$PKG_INFO"   || PKG_INFO="@PKG_INFO@"
test -n "$SED"        || SED="@SED@"
test -n "$SORT"	      || SORT="@SORT@"
test -n "$TSORT"      || TSORT="@TSORT@"
test -n "$XARGS"      || XARGS="@XARGS@"

MY_TMPDIR=`${MKTEMP} -d ${TMPDIR-/tmp}/${0##*/}.XXXXXX`
test -n "$MY_TMPDIR" || fatal "Couldn't create temporary directory."
MY_TMPFILE=$MY_TMPDIR/tmp

if [ -z "$MAKECONF" -o ! -f "$MAKECONF" ] ; then
    if [ -f @PREFIX@/etc/mk.conf ] ; then
	MAKECONF=@PREFIX@/etc/mk.conf
    elif [ -f /etc/mk.conf ] ; then
	MAKECONF=/etc/mk.conf
    else
	MAKECONF=/dev/null
    fi
fi
verbose_var MAKECONF

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
    printf '' > $opt_L
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

if [ "`${ID} -u`" = 0 ] ; then
    SU_CMD=
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

AWK_PARSE_SUMMARY='$1=="PKGNAME"{pkgname=$2} $1=="PKGPATH"{pkgpath=$2} NF==0{if (pkgpath && pkgname) print pkgpath ":" pkgname; pkgpath=""; pkgname=""} END{if (pkgpath && pkgname) print pkgpath ":" pkgname}'

if [ -n "$opt_b" -a -z "$opt_s" ] ; then
    case $PACKAGES in
	http://*|ftp://*)
            PKGDB=`ftp -o - $PACKAGES/$SUMMARY_FILE | ${GZIP_CMD} -cd \
		| ${AWK} -F= "$AWK_PARSE_SUMMARY"`
	    if [ -z "$PKGDB" ]
	    then
		PKGDB=`ftp -o - $PACKAGES/$OLD_SUMMARY_FILE`
	    fi;;
	*)
	    if [ -d "$PACKAGES" ] ; then
		msg_progress Scan $PACKAGES
		PKGDB=$(get_bin_pkg_info | bin_pkg_info2pkgdb)
		PKGSRCDIR=NONE
	    fi;;
    esac
fi

if [ -n "$opt_g" ]; then
    verbose "Write $PKGCHK_CONF based on installed packages"
    generate_conf_from_installed $PKGCHK_CONF
fi

if [ -n "$opt_r" -o -n "$opt_u" ];then
    verbose "Enumerate PKGDIRLIST from installed packages"
    PKGDIRLIST=$(pkgdirs_from_installed)
fi

if [ -n "$opt_p" ] ; then
    pkgdirs_from_conf $PKGCHK_CONF $PKGDIRLIST | tr ' ' '\n'
    exit
fi

if [ -n "$opt_a" -o -n "$opt_l" ];then	# Append to PKGDIRLIST based on conf
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
	    if [ -z "$opt_n" -a -z "$opt_q" ] ; then
		tmp=$(cat $PKGCHK_UPDATE_CONF)
		echo $tmp $(pkgdirs_from_installed) | tr ' ' '\n' | ${SORT} -u \
							> $PKGCHK_UPDATE_CONF
		tmp=
	    fi
	else
	    if [ -z "$opt_n" -a -z "$opt_q" ] ; then
		echo $(pkgdirs_from_installed) | tr ' ' '\n' \
							> $PKGCHK_UPDATE_CONF
	    fi
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
	if [ -n "$opt_a" -o -n "$opt_u" ]; then
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

if [ -n "$FAIL_DONE" ] ; then
   msg "Failed:$FAIL_DONE"
   cleanup_and_exit 1
fi

cleanup_and_exit
