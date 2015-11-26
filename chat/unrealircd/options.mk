# $NetBSD: options.mk,v 1.16 2015/11/26 16:36:00 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unrealircd

PKG_SUPPORTED_OPTIONS=	inet6 unrealircd-nospoof unrealircd-ziplinks
PKG_SUPPORTED_OPTIONS+= unrealircd-remoteinc ssl unrealircd-chroot
PKG_SUPPORTED_OPTIONS+=	unrealircd-prefixaq unrealircd-showlistmodes
PKG_SUPPORTED_OPTIONS+= unrealircd-topicisnuhost unrealircd-shunnotices
PKG_SUPPORTED_OPTIONS+= unrealircd-operoverride-verify
PKG_SUPPORTED_OPTIONS+=	unrealircd-no-operoverride unrealircd-disableusermod
PKG_SUGGESTED_OPTIONS=	unrealircd-showlistmodes unrealircd-prefixaq

.include "../../mk/bsd.options.mk"

###
### Enable IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
.else
CONFIGURE_ARGS+=	--disable-inet6
CONFIGURE_ENV+=		ac_cv_ip6=no
.endif

###
### Enable SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-ssl=${SSLBASE}
.endif

###
### Enable Anti-Spoofing protection for older OS's with an insecure IPv4 stack
###
.if !empty(PKG_OPTIONS:Munrealircd-nospoof)
CONFIGURE_ARGS+=	--enable-nospoof
.endif

###
### Compile in support for ziplinks.  This compresses data sent from
### server <-> server with zlib.
###
.if !empty(PKG_OPTIONS:Munrealircd-ziplinks)
CONFIGURE_ARGS+=		--enable-ziplinks=${BUILDLINK_PREFIX.zlib}
.	include "../../devel/zlib/buildlink3.mk"
.endif

###
### Compile in support for remote include files.
###
.if !empty(PKG_OPTIONS:Munrealircd-remoteinc)
CONFIGURE_ARGS+=		--enable-libcurl=${PREFIX}
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
CFLAGS+=		-DCHROOTDIR
CFLAGS+=		-DIRC_USER=\"${UIRCD_USER}\"
CFLAGS+=		-DIRC_GROUP=\"${UIRCD_GROUP}\"
CONFIGURE_ARGS+=	--disable-dynamic-linking
.else
CONFIGURE_ARGS+=	--enable-dynamic-linking
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
