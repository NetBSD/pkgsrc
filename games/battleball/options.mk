# $NetBSD: options.mk,v 1.1 2005/06/01 21:28:41 dillo Exp $

PKG_SUPPORTED_OPTIONS=		opengl
PKG_OPTIONS_LEGACY_VARS+=	BATTLEBALL_USE_MESA:opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CPPFLAGS+=      -DNO_OPENGL
SED_CMDS+=      -e '/^GLINCS/s|^|\#|' -e '/^GLLIBS/s|^|\#|'
.endif
