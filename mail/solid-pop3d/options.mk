# $NetBSD: options.mk,v 1.2 2012/06/12 15:45:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.solid-pop3d
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUPPORTED_OPTIONS+=	solid-pop3d-aliases
PKG_SUPPORTED_OPTIONS+=	solid-pop3d-apop
PKG_SUPPORTED_OPTIONS+=	solid-pop3d-standalone
PKG_SUGGESTED_OPTIONS=	inet6

PKG_OPTIONS_LEGACY_VARS+=	SPOP3D_ENABLE_ALIASES:solid-pop3d-aliases
PKG_OPTIONS_LEGACY_VARS+=	SPOP3D_ENABLE_APOP:solid-pop3d-apop
PKG_OPTIONS_LEGACY_VARS+=	SPOP3D_ENABLE_STANDALONE:solid-pop3d-standalone

.include "../../mk/bsd.options.mk"

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

###
### Support user names mapping and non-IP-based virtuals
###
.if !empty(PKG_OPTIONS:Msolid-pop3d-aliases)
CONFIGURE_ARGS+=	--enable-mapping
CONFIGURE_ARGS+=	--enable-nonip
.endif

###
### APOP support
###
.if !empty(PKG_OPTIONS:Msolid-pop3d-apop)
CONFIGURE_ARGS+=	--enable-apop
PLIST_SRC+=		${PKGDIR}/PLIST.apop
.endif

###
### Run as standalone daemon instead of via inetd
###
.if !empty(PKG_OPTIONS:Msolid-pop3d-standalone)
CONFIGURE_ARGS+=	--enable-standalone
CONFIGURE_ARGS+=	--enable-connect
.endif
