include $(EST)/config/systems/default.mak

## echo -n doesn't work (well only sometimes ?)
ECHO_N = /usr/bin/printf "%s"

NAWK=awk

NAS_LIB=$(PKG_PREFIX)/lib
NAS_INCLUDE=$(PKG_PREFIX)/include

X11_LIB=$(PKG_X11BASE)/lib
X11_INCLUDE=$(PKG_X11BASE)/include
