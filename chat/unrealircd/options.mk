# $NetBSD: options.mk,v 1.18 2020/01/28 13:03:36 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unrealircd

PKG_SUPPORTED_OPTIONS+=	unrealircd-remoteinc
PKG_SUPPORTED_OPTIONS+=	unrealircd-showlistmodes
PKG_SUPPORTED_OPTIONS+=	unrealircd-operoverride-verify
PKG_SUPPORTED_OPTIONS+=	unrealircd-no-operoverride
PKG_SUGGESTED_OPTIONS=	unrealircd-showlistmodes

.include "../../mk/bsd.options.mk"

###
### Compile in support for remote include files.
###
.if !empty(PKG_OPTIONS:Munrealircd-remoteinc)
CONFIGURE_ARGS+=		--enable-libcurl=${PREFIX}
.  include "../../www/curl/buildlink3.mk"
.endif

###
### Show the modes a channel has set in the /list output.
###
.if !empty(PKG_OPTIONS:Munrealircd-showlistmodes)
CONFIGURE_ARGS+=		--with-showlistmodes
.endif

###
### Disable oper override.
###
.if !empty(PKG_OPTIONS:Munrealircd-no-operoverride)
CONFIGURE_ARGS+=		--with-no-operoverride
.endif

###
### Require opers to /invite themselves into a +s or +p channel.
###
.if !empty(PKG_OPTIONS:Munrealircd-operoverride-verify)
CONFIGURE_ARGS+=		--with-operoverride-verify
.endif
