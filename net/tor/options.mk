# $NetBSD: options.mk,v 1.19 2021/06/27 21:18:38 wiz Exp $

# XXX Add rust to supported options.
PKG_OPTIONS_VAR=		PKG_OPTIONS.tor
PKG_SUPPORTED_OPTIONS=		doc
PKG_OPTIONS_REQUIRED_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		nss openssl
PKG_SUGGESTED_OPTIONS+=		doc openssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc openssl

###
### This enables the build of manual pages. It requires asciidoc
### at build time, which comes with a tail of dependencies and
### may not be wanted under certain circumstances.
###
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+=		asciidoc>=8.3.3:../../textproc/asciidoc
CONFIGURE_ARGS+=	--enable-asciidoc
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--disable-asciidoc
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=		yes
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnss)
CONFIGURE_ARGS+=	--enable-nss
.include "../../devel/nss/buildlink3.mk"
.endif

#.if !empty(PKG_OPTIONS:Mrust)
#CONFIGURE_ARGS+=	--enable-rust
#.include "../../lang/rust/buildlink3.mk"
#.endif
