# $NetBSD: options.mk,v 1.2 2012/06/12 15:46:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rbldnsd
PKG_SUPPORTED_OPTIONS=	inet6 rbldnsd-master-dump zlib
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--enable-zlib
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-zlib
.endif

.if !empty(PKG_OPTIONS:Mrbldnsd-master-dump)
CONFIGURE_ARGS+=	--enable-master-dump
.else
CONFIGURE_ARGS+=	--disable-master-dump
.endif
