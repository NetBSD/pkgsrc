# $NetBSD: options.mk,v 1.1 2011/04/04 09:13:44 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libVNCServer
PKG_SUPPORTED_OPTIONS=	gnutls inet6 libgcrypt
PKG_SUGGESTED_OPTIONS=	gnutls inet6 libgcrypt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
USE_TOOLS+=	pkg-config
CONFIGURE_ARGS+=	--with-gnutls
CONFIGURE_ARGS+=	--with-client-tls
.else
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--without-client-tls
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gcrypt
CONFIGURE_ARGS+=	--with-client-gcrypt
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}
.else
CONFIGURE_ARGS+=	--without-gcrypt
CONFIGURE_ARGS+=	--without-client-gcrypt
.endif
