#!/bin/sh -e
#
# $Id: pkgchk.sh,v 1.8 2001/07/31 17:32:07 tron Exp $
#
# TODO: Handle and as well as or tags (eg: i386+x11)
# TODO: Order updates based on DEPENDENCIES.
# TODO: Handle updates with dependencies via binary packages

extract_variables()
    {
    # Establish PKGSRCDIR
    #

    if [ -z "$PKGSRCDIR" ];then
	if [ -f /etc/mk.conf ] ;then
	    eval `printf 'BSD_PKG_MK=1\nall:\n\t@echo PKGSRCDIR=${PKGSRCDIR}\n' | ${MAKE} -f - -f /etc/mk.conf`
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
    #
    eval `printf 'CATEGORIES=x\nDISTNAME=x\nall:\n
	@echo PACKAGES=${PACKAGES}
	@echo PKGCHK_CONF=${PKGCHK_CONF}
    ' | (cd $PKGSRCDIR ; ${MAKE} -f - -f $PKGSRCDIR/mk/bsd.prefs.mk)`

    if [ -z "$PACKAGES" ];then
	PACKAGES=$PKGSRCDIR/packages
    fi

    if [ -z "$PKGCHK_CONF" ];then
	PKGCHK_CONF=$PKGSRCDIR/pkgchk.conf
    fi
    }

pkg_install()
    {
    PKGNAME=$1
    PKGDIR=$2
    INSTALL=$3
    if [ -n "$opt_b" -a -f $PACKAGES/All/$PKGNAME.tgz ] ; then
	if [ $INSTALL = U ];then
	    PKG=`echo $PKGNAME | sed 's/-[0-9].*//'`
	    echo "pkg_delete $PKG"
	    if [ -z "$opt_n" ];then
		if pkg_delete $PKG ; then
		    echo "Deleted $PKG"
		else
		    echo "Can only update packages with dependencies via -s"
		    exit 1
		fi
	    fi
	fi
	echo "pkg_add $PKGNAME.tgz"
	if [ -z "$opt_n" ];then
	    pkg_add $PACKAGES/All/$PKGNAME.tgz
	fi
    elif [ -n "$opt_s" ]; then
	echo "make update for $PKGNAME"
	cd $PKGSRCDIR/$PKGDIR
	if [ -z "$opt_n" ];then
	    ${MAKE} update
	fi
    fi
    }


get_build_version()
    {
    FILESDIR=`${MAKE} show-var VARNAME=FILESDIR`
    PKGDIR=`${MAKE} show-var VARNAME=PKGDIR`
    DISTINFO_FILE=`${MAKE} show-var VARNAME=DISTINFO_FILE`
    PATCHDIR=`${MAKE} show-var VARNAME=PATCHDIR`
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

args=`getopt BD:U:abchinsuv $*`
if [ $? != 0 ]; then
    opt_h=1
fi
set -- $args
while [ $# != 0 ]; do
    case "$1" in
	-B )    opt_B=1 ;;
	-D )	opt_D="$2" ; shift;;
	-U )	opt_U="$2" ; shift;;
	-a )	opt_a=1 ; opt_c=1 ;;
	-b )	opt_b=1 ;;
	-c )	opt_c=1 ;;
	-h )	opt_h=1 ;;
	-i )	opt_i=1 ;;
	-n )	opt_n=1 ;;
	-s )	opt_s=1 ;;
	-u )	opt_u=1 ;;
	-v )	opt_v=1 ;;
	-- )	break ;;
    esac
    shift
done

if [ -z "$opt_b" -a -z "$opt_s" ];then
    opt_b=1; opt_s=1;
fi

if [ -z "$opt_a" -a -z "$opt_c" -a -z "$opt_i" ];then
    echo "Must specify at least one of -a, -c, or -i";
    echo
    opt_h=1;
fi

if [ -n "$opt_h" -o $# != 1 ];then
    echo 'Usage: pkgchk [opts]
	-B      Check the "Build version" of packages
	-D tags Comma separated list of additional pkgchk.conf tags to set
	-U tags Comma separated list of pkgchk.conf tags to unset
	-a      Add all missing packages (implies -c)
	-b      Limit installations to binary packages
	-c      Check installed packages against pkgchk.conf
	-h      This help
	-i	Check versions of installed packages (ignore pkgchk.conf)
	-n	Display actions that would be taken, but do not perform them
	-s      Limit installations to building from source
	-u      Update all mismatched packages
	-v      Verbose

pkgchk verifies installed packages against pkgsrc.
The most common usage is 'pkgchk -i' to check all installed packages.
For more advanced usage, including defining a set of desired packages based
on hostname and type, see pkgchk(8).
'
    exit 1
fi

test -n "$MAKE" || MAKE="@MAKE@"

# grabbeb from GNU configure
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

cd $PKGSRCDIR
real_pkgsrcdir=`pwd`

cd pkgtools/pkgchk
AWK=`${MAKE} show-var VARNAME=AWK`
GREP=`${MAKE} show-var VARNAME=GREP`
SED=`${MAKE} show-var VARNAME=SED`


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
    if [ -f /usr/X11R6/lib/libX11.so -o /usr/X11R6/lib/libX11.a ];then
	TAGS="$TAGS,x11"
    fi
    if [ -n "$opt_D" ];then
	TAGS="$TAGS,$opt_D"
    fi
    if [ -n "$opt_v" ];then
	echo "set   TAGS=$TAGS"
	echo "unset TAGS=$opt_U"
    fi

    # Extract list of valid pkgdirs
    #
    PKGDIRLIST="$PKGDIRLIST "`${AWK} -v setlist=$TAGS -v unsetlist=$opt_U '
    BEGIN {
	split(setlist, tmp, ",");
	for (tag in tmp)
	    { taglist[tmp[tag]] = 1; }
	taglist["*"] = 1;
	split(unsetlist, tmp, ",");
	for (tag in tmp)
	    {
	    print "UN "notaglist[tag] > "/dev/stderr"
	    delete taglist[tmp[tag]]
	    }
	taglist["*"] = "*"
   	}
    {
    sub("#.*", "");
    split($0, chklist, "[ 	]*");
    need = 0;
    for (chk in chklist)			# For each word on the line
	{
	if (sub("^-", "", chklist[chk]))	# If it begins with a '-'
	    {
	    if (chklist[chk] in taglist)	# If match, discard
		{ next; }
	    }
	else
	    {
	    if (chklist[chk] in taglist)	# If match, note needed
		{ need = 1; }
	    }
	}
    if (need)
	{ print $1 }
    }
    ' < $PKGCHK_CONF
    `
fi

# Check packages are installed
#
for pkgdir in $PKGDIRLIST ; do

    if [ ! -f $PKGSRCDIR/$pkgdir/Makefile ];then
	echo "WARNING: No $pkgdir/Makefile - package moved or obsolete?"
	continue
    fi
    cd $PKGSRCDIR/$pkgdir
    # Use 'make x' rather than 'make all' to avoid potential licence errors
    pkgname=`printf 'x:\n\t@echo ${PKGNAME}\n'|${MAKE} -f - -f Makefile x` || true
    if [ -z "$pkgname" ]; then
	echo "Unable to extract PKGNAME for $pkgdir"
	exit 1
    fi
    if [ ! -d /var/db/pkg/$pkgname ];then
	echo $ac_n "$pkgname: $ac_c"
	pkg=`echo $pkgname | sed 's/-[0-9].*//'`
	pkginstalled=`pkg_info -e $pkg || true`
	INSTALL=
	if [ -n "$pkginstalled" ];then
	    echo $ac_n "version mismatch - $pkginstalled$ac_c"
	    if [ -n "$opt_u" ]; then
		UPDATE_TODO="$UPDATE_TODO $pkgname $pkgdir"
	    fi
	else
	    echo $ac_n "missing$ac_c"
	    if [ -n "$opt_a" ] ; then
		INSTALL_TODO="$INSTALL_TODO $pkgname $pkgdir"
	    fi
	fi
	if [ -f $PACKAGES/All/$pkgname.tgz ] ;then
	    echo $ac_n " (binary package available)$ac_c"
	fi
	echo
    else
	if [ -n "$opt_B" ];then
	    current_build_version=`get_build_version`
	    installed_build_version=`cat /var/db/pkg/$pkgname/+BUILD_VERSION`
	    if [ x"$current_build_version" != x"$installed_build_version" ];then
		echo "$pkgname: build version information mismatch"
		# should we mark this pkg to be updated if -u is given ??
	    elif [ -n "$opt_v" ];then
		echo "$pkgname: OK"
	    fi
	elif [ -n "$opt_v" ];then
	    echo "$pkgname: OK"
	fi
    fi
done

if [ -n "$UPDATE_TODO" ];then
    echo "Updating..."

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
	UPDATE_DONE=$UPDATE_DONE" "$1
	shift ; shift;
    done
fi

if [ -n "$INSTALL_TODO" ];then
    echo "Installing..."
    set -- $INSTALL_TODO
    while [ $# != 0 ]; do
	pkg_install $1 $2 I
	INSTALL_DONE=$INSTALL_DONE" "$1
	shift ; shift;
    done
fi

if [ -n "$UPDATE_DONE" ];then
    echo "Updated:$UPDATE_DONE"
fi
if [ -n "$INSTALL_DONE" ];then
    echo "Installed:$INSTALL_DONE"
fi
