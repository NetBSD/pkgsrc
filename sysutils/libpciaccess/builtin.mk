# $NetBSD: builtin.mk,v 1.1.2.1 2014/07/18 13:39:34 tron Exp $

BUILTIN_PKG:=	libpciaccess
PKGCONFIG_FILE.libpciaccess=	${X11BASE}/lib/pkgconfig/pciaccess.pc
PKGCONFIG_FILE.libpciaccess+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/pciaccess.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.libpciaccess?=	no
.if !empty(CHECK_BUILTIN.libpciaccess:M[nN][oO])
.  if !empty(MACHINE_PLATFORM:MNetBSD-5.[0-9]*-*) && \
	!empty(USE_BUILTIN.libpciaccess:M[yY][eE][sS])
BUILDLINK_TRANSFORM+=	l:pciaccess:pciaccess:z
.  endif
.endif  # CHECK_BUILTIN.libpciaccess
