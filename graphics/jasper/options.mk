# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.jasper
PKG_SUPPORTED_OPTIONS=	opengl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		opengl

.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_CONFIGURE_ARGS+=	-DJAS_ENABLE_OPENGL=ON
PLIST.opengl=	yes
.  if ${OPSYS} != "Darwin"
.    include "../../graphics/freeglut/buildlink3.mk"
.    include "../../x11/libXmu/buildlink3.mk"
.  endif
.else
CMAKE_CONFIGURE_ARGS+=	-DJAS_ENABLE_OPENGL=OFF
.endif
