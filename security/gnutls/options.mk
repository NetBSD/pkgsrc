# $NetBSD: options.mk,v 1.8.2.1 2026/05/07 22:32:20 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnutls
PKG_SUPPORTED_OPTIONS=	brotli dane pkcs11 zstd
PKG_SUGGESTED_OPTIONS=	pkcs11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdane)
.include "../../net/unbound/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdane
PLIST_SRC+=		PLIST.dane
.else
CONFIGURE_ARGS+=	--disable-libdane
.endif

PLIST_VARS+=	pkcs11
.if !empty(PKG_OPTIONS:Mpkcs11)
PLIST.pkcs11=	yes
BUILDLINK_API_DEPENDS.p11-kit+=	p11-kit>=0.23.1
PRINT_PLIST_AWK+=	{ gsub(/^bin\/p11tool/, "$${PLIST.pkcs11}&"); }
.include "../../security/p11-kit/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-p11-kit
.endif

.if !empty(PKG_OPTIONS:Mbrotli)
CONFIGURE_ARGS+=	--with-brotli
.include "../../archivers/brotli/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-brotli
.endif

.if !empty(PKG_OPTIONS:Mzstd)
CONFIGURE_ARGS+=	--with-zstd
.include "../../archivers/zstd/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-zstd
.endif
