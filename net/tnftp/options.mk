# $NetBSD: options.mk,v 1.14 2021/11/22 16:09:33 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tnftp
PKG_SUPPORTED_OPTIONS=	editline inet6 ssl socks

CHECK_BUILTIN.openssl:=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=	no

.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS+=	ssl
.endif

.include "../../mk/bsd.prefs.mk"

.if ${IPV6_READY:tl} == "yes"
PKG_SUGGESTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Meditline)
CONFIGURE_ARGS+=	--enable-editcomplete
.include "../../mk/termcap.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-editcomplete
.endif

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
