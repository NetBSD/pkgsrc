# $NetBSD: options.mk,v 1.1.1.1 2007/10/17 09:42:39 bjs Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.aria2

PKG_OPTIONS_GROUP.tls= 		gnutls ssl
PKG_OPTIONS_GROUP.asyncns= 	libares libcares

PKG_OPTIONS_REQUIRED_GROUPS= 	tls asyncns

PKG_SUPPORTED_OPTIONS+=		aria2-metalink
PKG_SUGGESTED_OPTIONS+=		ssl libcares aria2-metalink

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=		--with-openssl
CONFIGURE_ARGS+=		--without-gnutls

.include "../../security/openssl/buildlink3.mk"

.else
CONFIGURE_ARGS+=		--with-gnutls
CONFIGURE_ARGS+=		--without-openssl

.include "../../security/gnutls/buildlink3.mk"

.endif

.if !empty(PKG_OPTIONS:Mlibcares)
CONFIGURE_ARGS+=	--with-libcares-prefix=${BUILDLINK_PREFIX.libcares:Q}

.include "../../net/libcares/buildlink3.mk"

.elif !empty(PKG_OPTIONS:Mlibares)
CONFIGURE_ARGS+=	--with-libares-prefix=${BUILDLINK_PREFIX.libares:Q}

.endif


.if !empty(PKG_OPTIONS:Maria2-metalink)
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--enable-metalink
CONFIGURE_ARGS+=	--with-xml-prefix=${BULDLINK_PREFIX.libxml2:Q}

.include "../../textproc/libxml2/buildlink3.mk"

.else
CONFIGURE_ARGS+=	--without-libxml2
CONFIGURE_ARGS+=	--disable-metalink

.endif
