include $(EST)/config/systems/default.mak

## echo -n doesn't work (well only sometimes ?)
ECHO_N = /usr/bin/printf "%s"

NAWK=awk

NAS_LIB=${BUILDLINK_PREFIX.nas}/lib
NAS_INCLUDE=${BUILDLINK_PREFIX.nas}/include

X11_LIB=$(PKG_X11BASE)/lib
X11_INCLUDE=$(PKG_X11BASE)/include
