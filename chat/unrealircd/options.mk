# $NetBSD: options.mk,v 1.17 2019/02/09 15:23:15 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unrealircd

PKG_SUPPORTED_OPTIONS+=	unrealircd-remoteinc
PKG_SUPPORTED_OPTIONS+=	unrealircd-showlistmodes
PKG_SUPPORTED_OPTIONS+=	unrealircd-topicisnuhost unrealircd-shunnotices
PKG_SUPPORTED_OPTIONS+=	unrealircd-operoverride-verify
PKG_SUPPORTED_OPTIONS+=	unrealircd-no-operoverride unrealircd-disableusermod
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
### /topic command to show the nick!user@host of the person
### who set the topic, rather than just the nickname.
###
.if !empty(PKG_OPTIONS:Munrealircd-topicisnuhost)
CONFIGURE_ARGS+=		--with-topicisnuhost
.endif

###
### Notify a user when they are no longer shunned.
###
.if !empty(PKG_OPTIONS:Munrealircd-shunnotices)
CONFIGURE_ARGS+=		--with-shunnotices
.endif

###
### Disable oper override.
###
.if !empty(PKG_OPTIONS:Munrealircd-no-operoverride)
CONFIGURE_ARGS+=		--with-no-operoverride
.endif

###
### Disable /sethost, /setident, /chgname, /chghost, and /chgident.
###
.if !empty(PKG_OPTIONS:Munrealircd-disableusermod)
CONFIGURE_ARGS+=		--with-disableusermod
.endif

###
### Require opers to /invite themselves into a +s or +p channel.
###
.if !empty(PKG_OPTIONS:Munrealircd-operoverride-verify)
CONFIGURE_ARGS+=		--with-operoverride-verify
.endif
