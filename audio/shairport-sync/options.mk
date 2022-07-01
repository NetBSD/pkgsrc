# $NetBSD: options.mk,v 1.1 2022/07/01 18:36:27 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.shairport-sync

PKG_OPTIONS_REQUIRED_GROUPS=	ssl
PKG_OPTIONS_OPTIONAL_GROUPS=	dnssd
PKG_OPTIONS_GROUP.ssl=		openssl mbedtls
PKG_OPTIONS_GROUP.dnssd=	avahi dnssd

.include "../../mk/bsd.fast.prefs.mk"

PKG_SUPPORTED_OPTIONS+=		jack pulseaudio

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=		alsa
PKG_SUGGESTED_OPTIONS+=		alsa avahi
.else
PKG_SUGGESTED_OPTIONS+=		dnssd
.endif

PKG_SUGGESTED_OPTIONS+=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-alsa
.endif

.if !empty(PKG_OPTIONS:Mavahi)
.  include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-avahi
.endif

.if !empty(PKG_OPTIONS:Mdnssd)
.  include "../../net/mDNSResponder/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dns_sd
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jack
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pa
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=openssl
.endif

.if !empty(PKG_OPTIONS:Mmbedtls)
.  include "../../security/mbedtls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=mbedtls
.endif
