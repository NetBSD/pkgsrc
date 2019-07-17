# $NetBSD: cargo.mk,v 1.7 2019/07/17 11:04:45 fox Exp $
#
# Common logic that can be used by packages that depend on cargo crates
# from crates.io. This lets existing pkgsrc infrastructure fetch and verify
# cargo crates instead of using the rust package manager in the build phase.
# Inspired by cargo.mk from FreeBSD ports.
#
# Usage example:
#
# CARGO_CRATE_DEPENDS+=	sha1-0.20
# .include "../../lang/rust/cargo.mk"
# do-build:
# 	cargo build --locked --frozen
#
#
# If modifying the list of dependencies, re-run the build once without
# --locked --frozen to generate a new valid Cargo.lock.
#
# a list of CARGO_CRATE_DEPENDS can be generated via "make show-cargo-depends".
#
# See also www/geckodriver for a full example.

BUILD_DEPENDS+=	rust-[0-9]*:../../lang/rust

USE_TOOLS+=		bsdtar digest
CARGO_VENDOR_DIR=	${WRKDIR}/vendor

DISTFILES?=	${DEFAULT_DISTFILES}
.for _crate in ${CARGO_CRATE_DEPENDS}
DISTFILES+=	${_crate}.crate
SITES.${_crate}.crate+=	-${MASTER_SITE_CRATESIO}${_crate:C/-[0-9]+\.[0-9.]+.*$//}/${_crate:C/^.*-([0-9]+\.[0-9.]+.*)$/\1/}/download
EXTRACT_DIR.${_crate}.crate?=	${CARGO_VENDOR_DIR}
.endfor

post-extract: cargo-vendor-crates
.PHONY: cargo-vendor-crates
cargo-vendor-crates:
	@${STEP_MSG} "Extracting local cargo crates"
	${RUN}${MKDIR} ${WRKSRC}/.cargo
	${RUN}${PRINTF} "[source.crates-io]\nreplace-with = \"vendored-sources\"\n[source.vendored-sources]\ndirectory = \"${CARGO_VENDOR_DIR}\"\n" > ${WRKSRC}/.cargo/config
	${RUN}${MKDIR} ${CARGO_VENDOR_DIR}
.for _crate in ${CARGO_CRATE_DEPENDS}
	${RUN}${PRINTF} '{"package":"%s","files":{}}'	\
	  $$(${DIGEST} sha256 < ${_DISTDIR}/${_crate}.crate) \
	  > ${CARGO_VENDOR_DIR}/${_crate}/.cargo-checksum.json
.endfor

.PHONY: show-cargo-depends
show-cargo-depends:
	${RUN}${AWK} '/^\"checksum/ { print "CARGO_CRATE_DEPENDS+=\t" $$2 "-" $$3""; next } ' ${WRKSRC}/Cargo.lock
