# $NetBSD: options.mk,v 1.2 2020/11/06 12:15:54 nia Exp $

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
CONFIGURE_ARGS+=		--with-luaversion=-5.1
.  include "../../lang/lua51/buildlink3.mk"
.endif
