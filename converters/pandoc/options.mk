# $NetBSD: options.mk,v 1.2 2023/10/31 14:37:29 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pandoc
PKG_SUPPORTED_OPTIONS=	lua server
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

###
### Lua scripting engine, used for running filters, custom readers, and
### custom writers written in Lua.
###
.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	-f lua
.include "../../lang/hs-hslua-cli/buildlink3.mk"
.include "../../converters/hs-pandoc-lua-engine/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-f-lua
.endif

###
### Pandoc as an HTTP server providing a REST API to perform format
### conversions.
###
.if !empty(PKG_OPTIONS:Mserver)
CONFIGURE_ARGS+=	-f server
.include "../../converters/hs-pandoc-server/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../www/hs-wai-extra/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-f-server
.endif
