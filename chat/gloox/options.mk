# $NetBSD: options.mk,v 1.2 2014/05/06 08:41:38 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gloox
PKG_OPTIONS_REQUIRED_GROUPS=	tls
# TLS selections
PKG_OPTIONS_GROUP.tls=		gnutls openssl
# debugging
PKG_SUPPORTED_OPTIONS+=		debug
PKG_SUGGESTED_OPTIONS=		gnutls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gnutls openssl

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=		yes
CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}
.  include "../../security/gnutls/buildlink3.mk"
.  include "../../security/libgcrypt/buildlink3.mk"
USE_TOOLS+=		pkg-config
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=		yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.  include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
