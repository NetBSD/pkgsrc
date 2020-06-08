# $NetBSD: cargo.mk,v 1.15 2020/06/08 22:37:28 he Exp $
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

MASTER_SITES?=	-${MASTER_SITE_CRATESIO}${PKGBASE}/${PKGVERSION_NOREV}/download

.include "type.mk"

.if ${RUST_TYPE} != "bin"
BUILD_DEPENDS+=	rust-[0-9]*:../../lang/rust
.else
BUILD_DEPENDS+=	rust-[0-9]*:../../lang/rust-bin
.endif

USE_TOOLS+=		bsdtar digest
CARGO_VENDOR_DIR=	${WRKDIR}/vendor

DISTFILES?=			${DEFAULT_DISTFILES}
.for _crate in ${CARGO_CRATE_DEPENDS}
DISTFILES+=			${_crate}.crate
SITES.${_crate}.crate+=		-${MASTER_SITE_CRATESIO}${_crate:C/-[0-9]+\.[0-9.]+.*$//}/${_crate:C/^.*-([0-9]+\.[0-9.]+.*)$/\1/}/download
EXTRACT_DIR.${_crate}.crate?=	${CARGO_VENDOR_DIR}
.endfor

.include "../../mk/bsd.prefs.mk"
# Triggers NetBSD ld.so bug (PR toolchain/54192)
.if ${OPSYS} == "NetBSD" && !empty(MACHINE_PLATFORM:MNetBSD-9.99.*) && \
    !empty(MACHINE_PLATFORM:MNetBSD-[1-9][0-9].*)
MAKE_JOBS_SAFE=	no
.endif

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
	${RUN}${AWK} '/^name = / { split($$3, a, "\""); name=a[2]; } \
		/^version = / { split($$3, a, "\""); vers=a[2]; } \
		/^source = / { \
			print "CARGO_CRATE_DEPENDS+=\t" name "-" vers; \
			}' ${WRKSRC}/Cargo.lock
