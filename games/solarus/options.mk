# $NetBSD: options.mk,v 1.3 2020/06/28 09:29:16 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.solarus

PKG_SUPPORTED_OPTIONS=	luajit

.include "../../lang/LuaJIT2/platform.mk"
.if !empty(PLATFORM_SUPPORTS_LUAJIT:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS=	luajit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
CMAKE_ARGS+=	-DSOLARUS_USE_LUAJIT=ON
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
CMAKE_ARGS+=	-DSOLARUS_USE_LUAJIT=OFF
.  include "../../lang/lua51/buildlink3.mk"
.endif
