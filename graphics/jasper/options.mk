# $NetBSD: options.mk,v 1.1 2017/02/21 18:24:20 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jasper
PKG_SUPPORTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		opengl

.if empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=		-DJAS_ENABLE_OPENGL=OFF
.else
CMAKE_ARGS+=		-DJAS_ENABLE_OPENGL=ON
PLIST.opengl=		yes
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/glut/buildlink3.mk"
.  endif
.endif
