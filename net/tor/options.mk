# $NetBSD: options.mk,v 1.13 2020/11/12 22:56:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tor
PKG_SUPPORTED_OPTIONS=	doc # rust
PKG_SUGGESTED_OPTIONS+=	doc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc

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

### This enables building tor with rust as per
### https://trac.torproject.org/projects/tor/wiki/RustInTor
### XXX:
### As of 0.4.4.6 I am not sure how this is supposed to work.
.if !empty(PKG_OPTIONS:Mrust)
CONFIGURE_ENV+=		TOR_RUST_DEPENDENCIES=${WRKDIR}/vendor
CONFIGURE_ARGS+=	--enable-rust
CARGO_CRATE_DEPENDS+=	digest-0.7.2
CARGO_CRATE_DEPENDS+=	generic-array-0.9.0
CARGO_CRATE_DEPENDS+=	libc-0.2.39
CARGO_CRATE_DEPENDS+=	rand-0.5.0-pre.2
CARGO_CRATE_DEPENDS+=	rand_core-0.2.0-pre.0
CARGO_CRATE_DEPENDS+=	typenum-1.9.0

RUST_REQ=	1.34.0
.include "../../lang/rust/cargo.mk"

pre-configure:
	cd ${WRKSRC} && ${MKDIR} -p src/rust/target/release

.PHONY: show-tor-cargo-depends
# \todo: Maybe we should add a path option to show-cargo-depends.
show-tor-cargo-depends:
	${RUN}${AWK} '/^\"checksum/ { print "CARGO_CRATE_DEPENDS+=\t" $$2 "-" $$3""; next } ' ${WRKSRC}/src/rust/Cargo.lock

.else
CONFIGURE_ARGS+=	--disable-rust
.endif
