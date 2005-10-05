# $NetBSD: options.mk,v 1.3 2005/10/05 13:29:50 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.battleball
PKG_SUPPORTED_OPTIONS=		opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.else
CPPFLAGS+=      -DNO_OPENGL
SED_CMDS+=      -e '/^GLINCS/s|^|\#|' -e '/^GLLIBS/s|^|\#|'
.endif
