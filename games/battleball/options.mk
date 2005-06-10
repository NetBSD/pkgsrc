# $NetBSD: options.mk,v 1.2 2005/06/10 18:11:57 dillo Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.battleball
PKG_SUPPORTED_OPTIONS=		opengl
PKG_OPTIONS_LEGACY_VARS+=	BATTLEBALL_USE_MESA:opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CPPFLAGS+=      -DNO_OPENGL
SED_CMDS+=      -e '/^GLINCS/s|^|\#|' -e '/^GLLIBS/s|^|\#|'
.endif
