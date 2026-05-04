# $NetBSD: options.mk,v 1.1 2026/05/04 12:28:52 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jfsw
PKG_SUPPORTED_OPTIONS=	opengl
PKG_SUGGESTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
MAKE_FLAGS+=	USE_OPENGL=2
.else
MAKE_FLAGS+=	USE_OPENGL=0
.endif
