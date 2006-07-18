# $NetBSD: options.mk,v 1.9 2006/07/18 22:43:36 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unrealircd

PKG_OPTIONS_REQUIRED_GROUPS=	role
PKG_OPTIONS_GROUP.role=		unrealircd-leaf unrealircd-hub

PKG_SUPPORTED_OPTIONS=	inet6 unrealircd-nospoof unrealircd-leaf
PKG_SUPPORTED_OPTIONS+=	unrealircd-ziplinks unrealircd-remoteinc ssl
PKG_SUPPORTED_OPTIONS+=	unrealircd-chroot unrealircd-prefixaq
PKG_SUPPORTED_OPTIONS+=	unrealircd-showlistmodes unrealircd-topicisnuhost
PKG_SUPPORTED_OPTIONS+=	unrealircd-shunnotices unrealircd-operoverride-verify
PKG_SUPPORTED_OPTIONS+=	unrealircd-no-operoverride unrealircd-disableusermod
PKG_SUGGESTED_OPTIONS=	unrealircd-showlistmodes unrealircd-hub \
			unrealircd-prefixaq

.include "../../mk/bsd.options.mk"

###
### Enable IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
MESSAGE_SRC+=		${WRKDIR}/.MESSAGE_SRC.inet6
.else
CONFIGURE_ENV+=		ac_cv_ip6=no
.endif

###
### Enable SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=${SSLBASE:Q}
.endif

###
### Enable Anti-Spoofing protection for older OS's with an insecure IPv4 stack
###
.if !empty(PKG_OPTIONS:Munrealircd-nospoof)
CONFIGURE_ARGS+=	--enable-nospoof
.endif

###
### Compile as a hub or leaf server
###
.if !empty(PKG_OPTIONS:Munrealircd-hub)
CONFIGURE_ARGS+=	--enable-hub
.	elif !empty(PKG_OPTIONS:Munrealircd-leaf)
CONFIGURE_ARGS+=	--enable-leaf
.endif

###
### Compile in support for ziplinks.  This compresses data sent from
### server <-> server with zlib.
###
.if !empty(PKG_OPTIONS:Munrealircd-ziplinks)
CONFIGURE_ARGS+=		--enable-ziplinks
.	include "../../devel/zlib/buildlink3.mk"
.endif

###
### Compile in support for remote include files.
###
.if !empty(PKG_OPTIONS:Munrealircd-remoteinc)
CONFIGURE_ARGS+=		--enable-libcurl=${PREFIX:Q}
.	include "../../www/curl/buildlink3.mk"
.	include "../../net/libcares/buildlink3.mk"
.endif

###
### Compile in CHROOTDIR support.
### As far as pkgsrc goes this is just an expirement.  You should read the
### unrealircd docs/source for further information on this.  By default
### CHROOTDIR is defined as ${IRCD_HOME}.
###
.if !empty(PKG_OPTIONS:Munrealircd-chroot)
CFLAGS+=	-DCHROOTDIR
.endif

###
### Enable prefixes for chanadmin and chanowner.
### This will give +a the & prefix and ~ for +q (just like +o is @)
### Supported by the major clients:
###	mIRC, xchat, epic, eggdrop, Klient, PJIRC, etc.
### with the notable exceptions of:
###	irssi, KVIrc and CGI:IRC.
### This feature should be enabled/disabled network-wide.
###
.if !empty(PKG_OPTIONS:Munrealircd-prefixaq)
CONFIGURE_ARGS+=		--enable-prefixaq
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
