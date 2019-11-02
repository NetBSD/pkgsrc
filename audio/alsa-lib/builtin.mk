# $NetBSD: builtin.mk,v 1.2 2019/11/02 21:09:12 rillig Exp $

BUILTIN_PKG:=	alsa-lib

PKGCONFIG_FILE.alsa-lib=	/usr/lib/pkgconfig/alsa.pc
PKGCONFIG_BASE.alsa-lib=	/usr

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

CHECK_BUILTIN.alsa-lib?=	no
.if !empty(CHECK_BUILTIN.alsa-lib:M[nN][oO])

.  if !empty(USE_BUILTIN.alsa-lib:M[yY][eE][sS])
BUILDLINK_PREFIX.alsa-lib=	/usr
BUILDLINK_FILES.alsa-lib+=	lib/pkgconfig/alsa.pc
.  endif

.endif  # CHECK_BUILTIN.alsa-lib
