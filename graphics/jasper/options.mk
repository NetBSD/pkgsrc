# $NetBSD: options.mk,v 1.2 2020/07/21 07:31:28 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jasper
PKG_SUPPORTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		opengl

.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DJAS_ENABLE_OPENGL=ON
PLIST.opengl=	yes
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/freeglut/buildlink3.mk"
.  endif
.else
CMAKE_ARGS+=	-DJAS_ENABLE_OPENGL=OFF
.endif
