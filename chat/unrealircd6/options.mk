# $NetBSD: options.mk,v 1.1 2022/03/04 08:44:33 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unrealircd

PKG_SUPPORTED_OPTIONS+=	unrealircd-remoteinc
PKG_SUPPORTED_OPTIONS+=	unrealircd-operoverride-verify
PKG_SUPPORTED_OPTIONS+=	unrealircd-no-operoverride

.include "../../mk/bsd.options.mk"

###
### Compile in support for remote include files.
###
.if !empty(PKG_OPTIONS:Munrealircd-remoteinc)
CONFIGURE_ARGS+=		--enable-libcurl=${PREFIX}
.  include "../../www/curl/buildlink3.mk"
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
