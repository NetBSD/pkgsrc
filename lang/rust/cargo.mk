# $NetBSD: cargo.mk,v 1.1 2017/11/08 13:40:10 tnn Exp $
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
# See also www/geckodriver for a full example.

USE_TOOLS+=		bsdtar digest
CARGO_VENDOR_DIR=	${WRKDIR}/vendor

DISTFILES?=	${DEFAULT_DISTFILES}
.for _crate in ${CARGO_CRATE_DEPENDS}
DISTFILES+=	${_crate}.crate
SITES.${_crate}.crate+= -${MASTER_SITE_CRATESIO}${_crate:C/-[0-9.]+$//}/${_crate:C/^.*-([0-9.]+)$/\1/}/download
.endfor

post-extract: cargo-vendor-crates
.PHONY: cargo-vendor-crates
cargo-vendor-crates:
	@${STEP_MSG} "Extracting local cargo crates"
	${RUN}${MKDIR} ${WRKSRC}/.cargo
	${RUN}${PRINTF} "[source.crates-io]\nreplace-with = \"vendored-sources\"\n[source.vendored-sources]\ndirectory = \"${CARGO_VENDOR_DIR}\"\n" >> ${WRKSRC}/.cargo/config
	${RUN}${MKDIR} ${CARGO_VENDOR_DIR}
.for _crate in ${CARGO_CRATE_DEPENDS}
	${RUN}${TOOLS_PATH.bsdtar} -C ${CARGO_VENDOR_DIR} -xzf ${WRKDIR}/${_crate}.crate
	${RUN}${PRINTF} '{"package":"%s","files":{}}'	\
	  $$(${DIGEST} sha256 < ${WRKDIR}/${_crate}.crate) \
	  > ${CARGO_VENDOR_DIR}/${_crate}/.cargo-checksum.json
.endfor
