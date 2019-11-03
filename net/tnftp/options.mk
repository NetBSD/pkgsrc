# $NetBSD: options.mk,v 1.12 2019/11/03 11:45:55 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tnftp
PKG_SUPPORTED_OPTIONS=	inet6 ssl socks
PKG_SUGGESTED_OPTIONS=	inet6

CHECK_BUILTIN.openssl:=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=	no

.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS+=	ssl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msocks)
CONFIGURE_ARGS+=	--with-socks
.include "../../net/dante/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-socks
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-ssl
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
