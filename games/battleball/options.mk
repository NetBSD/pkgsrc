# $NetBSD: options.mk,v 1.5 2026/11/25 14:42:07 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.battleball
PKG_SUPPORTED_OPTIONS=		opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../mk/mesa.buildlink3.mk"
.else
CPPFLAGS+=	-DNO_OPENGL
SED_CMDS+=	-e '/^GLINCS/s|^|\#|' -e '/^GLLIBS/s|^|\#|'
.endif
