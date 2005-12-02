# $NetBSD: options.mk,v 1.1 2005/12/02 17:03:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tnftpd
PKG_SUPPORTED_OPTIONS=		inet6
PKG_OPTIONS_OPTIONAL_GROUPS+=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks4)
CONFIGURE_ARGS+=	--with-socks4
.include "../../net/socks4/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--with-socks5
.include "../../net/socks5/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
