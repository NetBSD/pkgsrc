# $NetBSD: options.mk,v 1.3 2020/06/28 09:29:16 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.love

PKG_SUPPORTED_OPTIONS=	luajit

.include "../../lang/LuaJIT2/platform.mk"
.if !empty(PLATFORM_SUPPORTS_LUAJIT:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS=	luajit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
# JIT needs WX mappings
NOT_PAX_MPROTECT_SAFE+=		love0.10/bin/love
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--with-lua=lua
CONFIGURE_ARGS+=		--with-luaversion=-5.1
.  include "../../lang/lua51/buildlink3.mk"
.endif
