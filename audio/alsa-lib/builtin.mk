# $NetBSD: builtin.mk,v 1.3 2023/11/23 16:20:03 wiz Exp $

BUILTIN_PKG:=	alsa-lib

PKGCONFIG_FILE.alsa-lib=	/usr/lib/pkgconfig/alsa.pc
PKGCONFIG_BASE.alsa-lib=	/usr

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

CHECK_BUILTIN.alsa-lib?=	no
.if ${CHECK_BUILTIN.alsa-lib:tl} == no

.  if ${USE_BUILTIN.alsa-lib:tl} == yes
BUILDLINK_PREFIX.alsa-lib=	/usr
BUILDLINK_FILES.alsa-lib+=	lib/pkgconfig/alsa.pc
.  endif

.endif  # CHECK_BUILTIN.alsa-lib
