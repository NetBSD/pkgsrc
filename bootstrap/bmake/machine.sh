:
# derrived from /etc/rc_d/os.sh

# RCSid:
#	$Id: machine.sh,v 1.1.1.1 2004/03/11 13:04:08 grant Exp $
#
#	@(#) Copyright (c) 1994 Simon J. Gerraty
#
#	This file is provided in the hope that it will
#	be of use.  There is absolutely NO WARRANTY.
#	Permission to copy, redistribute or otherwise
#	use this file is hereby granted provided that 
#	the above copyright notice and this notice are
#	left intact. 
#      
#	Please send copies of changes and bug-fixes to:
#	sjg@quick.com.au
#

OS=`uname`
OSREL=`uname -r`
OSMAJOR=`IFS=.; set $OSREL; echo $1`
machine=`uname -m`
MACHINE=

# Great! Solaris keeps moving arch(1)
# we need this here, and it is not always available...
Which() {
	for d in `IFS=:; echo ${2:-$PATH}`
	do
		test -x $d/$1 && { echo $d/$1; break; }
	done
}

arch=`Which arch /usr/bin:/usr/ucb:$PATH`
test "$arch" && MACHINE_ARCH=`$arch`

case $OS in
OpenBSD)
	MACHINE=$OS$OSMAJOR.$machine
	MACHINE_ARCH=`$arch -s`;
	;;
*BSD)
	MACHINE=$OS$OSMAJOR.$machine
	;;
SunOS)
        MACHINE=$OS$OSMAJOR
        case "$MACHINE_ARCH" in
	sparc|sun4*)	;;
	sun386*) MACHINE=$MACHINE_ARCH;;
	*)	MACHINE=$MACHINE.$machine;;
	esac
	;;
HP-UX)
	MACHINE_ARCH=`IFS="/-."; set $machine; echo $1`
	;;
IRIX)
	MACHINE_ARCH=`uname -p 2>/dev/null`
	;;
Interix)
	MACHINE=i386
	MACHINE_ARCH=i386
	;;
esac

MACHINE=${MACHINE:-$OS$OSMAJOR}
MACHINE_ARCH=${MACHINE_ARCH:-$machine}


(
case "$0" in
arch*)	echo $MACHINE_ARCH;;
*)
	case "$1" in
	"")	echo $MACHINE;;
	*)	echo $MACHINE_ARCH;;
	esac
	;;
esac
) | tr ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz
