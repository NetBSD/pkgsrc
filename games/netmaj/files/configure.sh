#!/bin/sh
#
# $NetBSD: configure.sh,v 1.2 2009/03/11 19:11:59 hasso Exp $
#
# This script needs the following variables passed through the environment:
#
#	OPSYS		== ${OPSYS}
#	CURSES_LIBS	== ${BUILDLINK_LDADD.curses}
#

# Assume we always have gettimeofday().
cppflags="-DHAVE_GETTIMEOFDAY"

# "Test" whether to use termios routines or use ioctls to fiddle with ttys.
if test -d /usr/include/termios.h; then
	cppflags="$cppflags -DUSE_TERMIOS"
else
	cppflags="$cppflags -DUSE_SGTTY"
fi

# OS-specific stuff
case ${OPSYS} in
*BSD)
	;;
DragonFly)
	;;
Linux)
	cppflags="$cppflags -DDEF_OPTARG"
	;;
SunOS)
	cppflags="$cppflags -DSYSV -DUSE_RAND"
	libs="-lsocket -lnsl"
	;;
AIX)
	cppflags="$cppflags -DSYSV -DUSE_RAND -DOLD_SELECT -DUSE_WAIT3"
	;;
*)
	cppflags="$cppflags -DSYSV -DUSE_RAND"
	;;
esac

# Don't build the keypad support.
cppflags="$cppflags -DNO_KEYPAD"

cat > config.mk << EOF
OS_CFLAGS=	$cppflags
LIBS=		$libs
CURSES=		${CURSES_LIBS}
EOF

echo "Using the following configuration:"
cat config.mk

exit 0
