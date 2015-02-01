# $NetBSD: options.mk,v 1.9 2015/02/01 08:58:52 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tnftp
PKG_SUPPORTED_OPTIONS=		inet6
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks5
PKG_SUGGESTED_OPTIONS=		inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--with-socks
.include "../../net/socks5/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-socks
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
