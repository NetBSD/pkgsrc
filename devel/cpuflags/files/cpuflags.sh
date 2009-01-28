#!@@SH@@
# $NetBSD: cpuflags.sh,v 1.7 2009/01/28 23:30:50 abs Exp $
PATH=/sbin:/usr/sbin:/bin:/usr/bin:$PATH

# cd to the directory containing the binary, so we can usefully check for
# include files from there
case "$0" in
    /*) cd $(dirname $0);;
    *)  cd $(dirname $PWD/$0);;
esac

include()
    {
    file=$1
    if [ -f ./$file ] ; then
	file=./$file
    else
	file=@PREFIX@/share/cpuflags/$file
    fi
    verbose . $file
    . $file
    }

verbose()
    {
    [ -n "$opt_v" ] && echo $* >&2
    return 0
    }

UNAME=$(uname)

if [ "$1" = -v ] ; then
    shift
    opt_v=1
fi

if [ -n "$1" ]; then
    CC=$1
else
    CC=gcc
fi

# Each UNAME subr_ file is expected to set AWK & SED, and to provide the
# following methods:
#  extract_hw_details:	Must be called before determine_arch/determine_features
#  determine_arch:	Returns cpu arch
#  determine_features:	Returns cpu features
#  display_hw_details:	Human readable output for current machine
#
include subr_${UNAME}

# This provides gcc_ser(), gcc_ver() and gcc_fixup_arch_flags()
#
include subr_gcc

# native arch
M_ARCH_NATIVE='-march=native'

# Determine the flags for this OS/machine
extract_hw_details
if [ $(gcc_ser $CC) -gt 4002 ] ; then
    ARCH="$M_ARCH_NATIVE"
else
    ARCH=$(determine_arch)
fi
FEATURES=$(determine_features)

test "x$ARCH" != "x$M_ARCH_NATIVE" &&	# gcc have not autodetection
    case "$hw_machine_arch" in		# all known x86 mnemonics
    i386|i486|i586|i686|x86_64|amd64|i86pc)
	include subr_x86	# this provides flags_fixup_x86arch()
	l_arch=$(flags_fixup_x86arch "$ARCH" "$FEATURES")
	test -n "$l_arch" && ARCH="-march=$l_arch"
    esac

# Fixup any flags which are too new for our gcc version
#
CPUFLAGS=$(gcc_fixup_arch_flags $CC $ARCH $FEATURES)
CPUFLAGS=$(echo $CPUFLAGS)

if [ -n "$opt_v" ] ; then
    if [ -n "$NOARCH" ] ; then
	ARCH="No flags for this architecture"
    fi
    if [ -z "$ARCH" ]; then
	ARCH=Unknown
    fi
    cat <<END
ARCH            : $ARCH
FEATURES        : $FEATURES
CPUFLAGS        : $CPUFLAGS
GCC version     : $(gcc_ver $CC)
END
    display_hw_details
    exit;
fi

if [ -z "$ARCH" -a -z "$NOARCH" ] ; then
    echo 'Unknown machine - please send cpuflags details to abs@absd.org' >&2
    display_hw_details							  >&2
fi

echo $CPUFLAGS
exit 0
