# $NetBSD: x11.builtin.mk,v 1.2.20.1 2008/09/26 19:58:13 cube Exp $
#
# x11.builtin.mk will include the builtin.mk file from the appropriate
# X11 distribution.
#
# BUILTIN_PKG and USE_BUILTIN.<BUILTIN_PKG> must be defined by the caller

CHECK_BUILTIN.${BUILTIN_PKG}?=	no
.if !empty(CHECK_BUILTIN.${BUILTIN_PKG}:M[Nn][Oo])
.  if !empty(USE_BUILTIN.${BUILTIN_PKG}:M[Yy][Ee][Ss])

BUILDLINK_PREFIX.${BUILTIN_PKG}=	${X11BASE}

.    include "../../mk/x11.buildlink3.mk"
.    include "../../mk/x11.version.mk"
.    include "${X11_PKGSRCDIR.${X11_TYPE}}/builtin.mk"

.  endif
.endif
