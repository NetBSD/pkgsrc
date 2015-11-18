# $NetBSD: options.mk,v 1.2 2015/11/18 21:00:51 christos Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.${PKGNAME}
PKG_OPTIONS_REQUIRED_GROUPS=	crypto
PKG_OPTIONS_GROUP.crypto=	openssl libgcrypt
#PKG_SUPPORTED_OPTIONS=		compression
PKG_SUGGESTED_OPTIONS=		openssl # XXX zlib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2
CONFIGURE_ARGS+=		--with-libz=${BUILDLINK_PREFIX.zlib:Q}
.include "../../devel/zlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.8
CONFIGURE_ARGS+=		--with-libgcrypt=no
CONFIGURE_ARGS+=		--with-openssl=${SSLBASE:Q}
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.4
CONFIGURE_ARGS+=		--with-libgcrypt=${BUILDLINK_PREFIX.libgcrypt:Q}
CONFIGURE_ARGS+=		--with-openssl=no
.include "../../security/libgcrypt/buildlink3.mk"
.endif
