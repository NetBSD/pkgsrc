# $NetBSD: options.mk,v 1.2 2005/11/29 21:11:55 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unrealircd
PKG_SUPPORTED_OPTIONS=	inet6 nospoof hub leaf ziplinks remoteinc ssl chroot
PKG_SUPPORTED_OPTIONS+=	prefixaq showlistmodes topicisnuhost shunnotices
PKG_SUPPORTED_OPTIONS+=	no-operoverride disableusermod operoverride-verify
PKG_SUGGESTED_OPTIONS=	hub showlistmodes

.include "../../mk/bsd.options.mk"

###
### Can't be both a leaf and a hub IRC server
###
.if !empty(PKG_OPTIONS:Mhub) && !empty(PKG_OPTIONS:Mleaf)
PKG_FAIL_REASON+=	"The server cannot be both a hub and a leaf." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif

###
### Enable IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
MESSAGE_SRC+=		${WRKDIR}/.MESSAGE_SRC.inet6
.else
CONFIGURE_ENV+= 	ac_cv_ip6=no
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
.if !empty(PKG_OPTIONS:Mnospoof)
CONFIGURE_ARGS+=	--enable-nospoof
.endif

###
### Compile as a hub or leaf server
###
.if !empty(PKG_OPTIONS:Mhub)
CONFIGURE_ARGS+=	--enable-hub
.	elif !empty(PKG_OPTIONS:Mleaf)
CONFIGURE_ARGS+=	--enable-leaf
.endif

###
### Compile in support for ziplinks.  This compresses data sent from
### server <-> server with zlib.
###
.if !empty(PKG_OPTIONS:Mziplinks)
CONFIGURE_ARGS+=		--enable-ziplinks
.	include "../../devel/zlib/buildlink3.mk"
.endif

###
### Compile in support for remote include files.
###
.if !empty(PKG_OPTIONS:Mremoteinc)
CONFIGURE_ARGS+=		--enable-libcurl
.	include "../../www/curl/buildlink3.mk"
.	include "../../wip/c-ares/buildlink3.mk"
.endif

###
### Compile in CHROOTDIR support.
### As far as pkgsrc goes this is just an expirement.  You should read the
### unrealircd docs/source for further information on this.  By default
### CHROOTDIR is defined as ${IRCD_HOME}.
###
.if !empty(PKG_OPTIONS:Mchroot)
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
.if !empty(PKG_OPTIONS:Mprefixaq)
CONFIGURE_ARGS+=		--enable-prefixaq
.endif

###
### Show the modes a channel has set in the /list output.
###
.if !empty(PKG_OPTIONS:Mshowlistmodes)
CONFIGURE_ARGS+=		--with-showlistmodes
.endif

###
### /topic command to show the nick!user@host of the person
### who set the topic, rather than just the nickname.
###
.if !empty(PKG_OPTIONS:Mtopicisnuhost)
CONFIGURE_ARGS+=		--with-topicisnuhost
.endif

###
### Notify a user when they are no longer shunned.
###
.if !empty(PKG_OPTIONS:Mshunnotices)
CONFIGURE_ARGS+=		--with-shunnotices
.endif

###
### Disable oper override.
###
.if !empty(PKG_OPTIONS:Mno-operoverride)
CONFIGURE_ARGS+=		--with-no-operoverride
.endif

###
### Disable /sethost, /setident, /chgname, /chghost, and /chgident.
###
.if !empty(PKG_OPTIONS:Mdisableusermod)
CONFIGURE_ARGS+=		--with-disableusermod
.endif

###
### Require opers to /invite themselves into a +s or +p channel.
###
.if !empty(PKG_OPTIONS:Moperoverride-verify)
CONFIGURE_ARGS+=		--with-operoverride-verify
.endif
