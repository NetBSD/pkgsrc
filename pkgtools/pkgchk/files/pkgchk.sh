#!/bin/sh -e
#
# $Id: pkgchk.sh,v 1.1.1.1 2001/07/02 14:12:30 abs Exp $

extract_variables()
    {
    # Establish PKGSRCDIR
    #

    if [ -z "$PKGSRCDIR" ];then
	if [ -f /etc/mk.conf ] ;then
	    eval `printf 'all:\n\t@echo PKGSRCDIR=${PKGSRCDIR}\n' | make -f - -f /etc/mk.conf`
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
    ' | (cd $PKGSRCDIR ; make -f - -f $PKGSRCDIR/mk/bsd.prefs.mk)`

    if [ -z "$PACKAGES" ];then
	PACKAGES=$PKGSRCDIR/packages
    fi

    if [ -z "$PKGCHK_CONF" ];then
	PKGCHK_CONF=$PKGSRCDIR/pkgchk.conf
    fi
    if [ ! -r $PKGCHK_CONF ];then
	echo "Unable to read PKGCHK_CONF '$PKGCHK_CONF'"
	exit 1;
    fi
    }

pkg_install()
    {
    PKGNAME=$1
    PKGDIR=$2
    INSTALL=$3
    if [ -n "$opt_b" -a -f $PACKAGES/All/$PKGNAME.tgz ] ; then
	if [ $INSTALL = U ];then
	    if pkg_delete $PKGNAME ; then
		echo "Deleted $PKGNAME"
	    else
		echo "Can only update packages with dependencies via -s"
	    fi
	fi
	echo "Installing binary package $PKGNAME.tgz"
	pkg_add $PACKAGES/All/$PKGNAME.tgz
    elif [ -n "$opt_s" ]; then
	echo "Building $PKGNAME"
	cd $PKGSRCDIR/$PKGDIR
	make update
    fi
    }

args=`getopt D:IU:abchisuv $*`
if [ $? != 0 ]; then
    opt_h=1
fi
set -- $args
while [ $# != 0 ]; do
    case "$1" in
	-D )	opt_D="$2" ; shift;;
	-U )	opt_U="$2" ; shift;;
	-a )	opt_a=1 ; opt_c=1 ;;
	-b )	opt_b=1 ;;
	-c )	opt_c=1 ;;
	-h )	opt_h=1 ;;
	-i )	opt_i=1 ;;
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
	-D tags Comma separated list of additional pkgchk.conf tags to set
	-U tags Comma separated list of pkgchk.conf tags to unset
	-a      Add all missing packages (implies -c)
	-b      Limit installations to binary packages
	-c      Check installed packages against pkgchk.conf
	-h      This help
	-i	Check versions of installed packages (ignore pkgchk.conf)
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

extract_variables

if [ -n "$opt_i" ];then
    PKGDIRLIST=`pkg_info -B \* | awk '/PKGPATH= /{print $2}'`
fi

if [ -n "$opt_c" ];then
    # Determine list of tags
    #
    TAGS="`hostname -s`,`hostname`,`uname -srm | awk '{print $1"-"$2"-"$3","$1"-"$2","$1"-"$3","$1","$2","$3}'`"
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
    PKGDIRLIST="$PKGDIRLIST "`awk -v setlist=$TAGS -v unsetlist=$opt_U '
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
    cd $PKGSRCDIR/$pkgdir
    # Use 'make x' rather than 'make all' to avoid potential licence errors
    pkgname=`printf 'x:\n\t@echo ${PKGNAME}\n'|make -f - -f Makefile x`
    if [ -z "$pkgname" ]; then
	echo "Unable to extract PKGNAME for $pkgdir"
	exit 1
    fi

    if [ ! -d /var/db/pkg/$pkgname ];then
	echo -n "$pkgname: "
	pkg=`echo $pkgname | sed 's/-[0-9].*//'`
	pkginstalled=`pkg_info -e $pkg || true`
	INSTALL=
	if [ -n "$pkginstalled" ];then
	    echo -n "version mismatch - $pkginstalled"
	    if [ -n "$opt_u" ]; then
		INSTALL=U
	    fi
	else
	    echo -n "missing"
	    if [ -n "$opt_a" ] ; then
		INSTALL=I
	    fi
	fi
	if [ -f $PACKAGES/All/$pkgname.tgz ] ;then
	    echo -n " (binary package available)"
	fi
	echo
	if [ -n "$INSTALL" ];then
	    pkg_install $pkgname $pkgdir $INSTALL
	fi
     elif [ -n "$opt_v" ];then
	echo "$pkgname: OK"
    fi
done
