# $NetBSD: options.mk,v 1.3 2022/01/04 11:01:42 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.love
PKG_SUPPORTED_OPTIONS=	luajit

.include "../../lang/LuaJIT2/platform.mk"
.if !empty(PLATFORM_SUPPORTS_LUAJIT:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS=	luajit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--with-lua=lua
CONFIGURE_ARGS+=		--with-luaversion=-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
.  include "../../lang/lua/buildlink3.mk"
.endif
