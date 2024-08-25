# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.solarus

PKG_SUPPORTED_OPTIONS=	luajit

.include "../../lang/LuaJIT2/platform.mk"
.if !empty(PLATFORM_SUPPORTS_LUAJIT:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS=	luajit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
CMAKE_CONFIGURE_ARGS+=	-DSOLARUS_USE_LUAJIT=ON
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DSOLARUS_USE_LUAJIT=OFF
.  include "../../lang/lua51/buildlink3.mk"
.endif
