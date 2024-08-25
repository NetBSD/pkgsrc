# $NetBSD: options.mk,v 1.7 2024/08/25 06:18:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mgba

PKG_SUPPORTED_OPTIONS+=	opengl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GL=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_EPOXY=ON
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_GL=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_EPOXY=OFF
.endif
