# $NetBSD: options.mk,v 1.4 2018/07/29 07:40:06 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mailfront
PKG_SUPPORTED_OPTIONS+=	lua gnutls
PKG_SUGGESTED_OPTIONS+=	gnutls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		lua
.if !empty(PKG_OPTIONS:Mlua)
LUA_VERSIONS_ACCEPTED=	51
.  include "../../lang/lua/buildlink3.mk"
BUILD_TARGET+=		lua
PLIST.lua=		yes
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
BUILDLINK_API_DEPENDS.gnutls+=  gnutls>=3.5.0
.  include "../../security/gnutls/buildlink3.mk"
DJB_CONFIG_CMDS+=	${ECHO} gnutls > conf-tls;
USE_TOOLS+=		pkg-config
.else
DJB_CONFIG_CMDS+=	${ECHO} none > conf-tls;
.endif
