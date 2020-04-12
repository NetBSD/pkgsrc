# $NetBSD: options.mk,v 1.3 2020/04/12 07:21:04 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxml2
PKG_SUPPORTED_OPTIONS+=	icu inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
CONFIGURE_ARGS+=	--with-icu
.else
CONFIGURE_ARGS+=	--without-icu
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
