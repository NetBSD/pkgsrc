# $NetBSD: options.mk,v 1.6 2022/12/15 11:31:44 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mgba

PKG_SUPPORTED_OPTIONS+=	opengl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	opengl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopengl)
CMAKE_ARGS+=	-DBUILD_GL=ON
CMAKE_ARGS+=	-DUSE_EPOXY=ON
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_GL=OFF
CMAKE_ARGS+=	-DUSE_EPOXY=OFF
.endif
