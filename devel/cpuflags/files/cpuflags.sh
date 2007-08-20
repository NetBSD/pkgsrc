#!/bin/sh
# $NetBSD: cpuflags.sh,v 1.1 2007/08/20 11:21:21 abs Exp $
PATH=/sbin:/usr/sbin:/bin:/usr/bin:$PATH

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

# Determine the flags for this OS/machine
extract_hw_details
if [ $(gcc_ser $CC) -gt 4002 ] ; then
    ARCH='-march=native'
else
    ARCH=$(determine_arch)
fi
FEATURES=$(determine_features)

# Fixup any flags which are too new for our gcc version
#
CPUFLAGS="$(gcc_fixup_arch_flags $CC $ARCH $FEATURES)"
CPUFLAGS="$(echo $CPUFLAGS)"

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
    echo 'Unknown machine - please send details to abs@absd.org'	>&2
    display_hw_details							>&2
fi

echo $CPUFLAGS
exit 0
