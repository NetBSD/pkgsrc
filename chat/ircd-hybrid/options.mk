# $NetBSD: options.mk,v 1.1 2005/11/13 22:40:00 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ircd-hybrid
PKG_SUPPORTED_OPTIONS=	efnet ssl halfops small-net ziplinks

PKG_SUGGESTED_OPTIONS=	ssl ziplinks

.include "../../mk/bsd.options.mk"

###
### Tweak some options to be EFNet based
###
.if !empty(PKG_OPTIONS:Mefnet)
CONFIGURE_ARGS+=	--enable-efnet
.endif

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

###
### Halfops are similar to plain ops, but can't kick/deop plain ops. Halfops
### may or may not kick/deop other halfops depending on if (+p) is set.
### Halfops may not set (+/-p).
###
.if !empty(PKG_OPTIONS:Mhalfops)
CONFIGURE_ARGS+=	--enable-halfops
.endif

###
### Tunes the server for smaller networks by reducing the startup
### memory footprint.
###
.if !empty(PKG_OPTIONS:Msmall-net)
CONFIGURE_ARGS+=	--enable-small-net
.endif

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mziplinks)
.	include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-zlib
.else
CONFIGURE_ARGS+=	--disable-zlib
.endif
