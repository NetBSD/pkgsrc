include $(EST)/config/systems/default.mak

## echo -n doesn't work (well only sometimes ?)
ECHO_N = /usr/bin/printf "%s"

NAWK=awk

NAS_LIB=${BUILDLINK_DIR}/lib
NAS_INCLUDE=${BUILDLINK_DIR}/include

X11_LIB=$(PKG_X11BASE)/lib
X11_INCLUDE=$(PKG_X11BASE)/include
