# $NetBSD: options.mk,v 1.2 2020/06/24 11:43:54 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.love
PKG_SUPPORTED_OPTIONS=	luajit

.include "../../lang/LuaJIT2/platform.mk"
.if !empty(PLATFORM_SUPPORTS_LUAJIT:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS=	luajit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
CONFIGURE_ARGS+=	--enable-luajit
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
SUBST_CLASSES+=		lua
SUBST_STAGE.lua=	pre-configure
SUBST_FILES.lua=	configure
SUBST_SED.lua=		-e 's,luajit-5.1,lua-5.1,g'
.  include "../../lang/lua51/buildlink3.mk"
.endif
