# $NetBSD: options.mk,v 1.20 2021/06/28 07:03:44 wiz Exp $

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

# see
# https://gitlab.torproject.org/tpo/core/arti
# instead
#.if !empty(PKG_OPTIONS:Mrust)
#CONFIGURE_ARGS+=	--enable-rust
#CONFIGURE_ENV+=		TOR_RUST_DEPENDENCIES=${WRKDIR}/vendor
##CONFIGURE_ARGS+=	--enable-cargo-online-mode
## needed to override cargo.mk
#do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} all
#CARGO_CRATE_DEPENDS+=   digest-0.7.2
#CARGO_CRATE_DEPENDS+=   generic-array-0.9.0
#CARGO_CRATE_DEPENDS+=   libc-0.2.39
#CARGO_CRATE_DEPENDS+=   rand-0.5.0-pre.2
#CARGO_CRATE_DEPENDS+=   rand_core-0.2.0-pre.0
#CARGO_CRATE_DEPENDS+=   typenum-1.9.0
#.include "../../lang/rust/buildlink3.mk"
#.include "../../lang/rust/cargo.mk"
#.endif
