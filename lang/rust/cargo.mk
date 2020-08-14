# $NetBSD: cargo.mk,v 1.22 2020/08/14 21:19:22 tnn Exp $
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
#
# If modifying the list of dependencies, re-run the build once without
# --offline in CARGO_ARGS to generate a new valid Cargo.lock.
# e.g: make CARGO_ARGS="build --release" build
#
# a list of CARGO_CRATE_DEPENDS can be generated via
#      make print-cargo-depends > cargo-depends.mk
#
# See also www/geckodriver for a full example.

MASTER_SITES?=	-${MASTER_SITE_CRATESIO}${PKGBASE}/${PKGVERSION_NOREV}/download

.include "../../lang/rust/rust.mk"

USE_TOOLS+=		bsdtar digest
CARGO_VENDOR_DIR=	${WRKDIR}/vendor

DISTFILES?=			${DEFAULT_DISTFILES}
.for crate in ${CARGO_CRATE_DEPENDS}
DISTFILES+=			${crate}.crate
SITES.${crate}.crate+=		-${MASTER_SITE_CRATESIO}${crate:C/-[0-9]+\.[0-9.]+.*$//}/${crate:C/^.*-([0-9]+\.[0-9.]+.*)$/\1/}/download
EXTRACT_DIR.${crate}.crate?=	${CARGO_VENDOR_DIR}
.endfor

.include "../../mk/bsd.prefs.mk"
# Triggers NetBSD ld.so bug (PR toolchain/54192)
# See Makefile for further information.
.if ${MACHINE_PLATFORM:MNetBSD-[1-9].*} && !${MACHINE_PLATFORM:MNetBSD-9.99.*}
MAKE_JOBS_SAFE=	no
.endif

post-extract: cargo-vendor-crates
.PHONY: cargo-vendor-crates
cargo-vendor-crates:
	@${STEP_MSG} "Extracting local cargo crates"
	${RUN}${MKDIR} ${WRKSRC}/.cargo
	${RUN}${PRINTF} "[source.crates-io]\nreplace-with = \"vendored-sources\"\n[source.vendored-sources]\ndirectory = \"${CARGO_VENDOR_DIR}\"\n" > ${WRKSRC}/.cargo/config
	${RUN}${MKDIR} ${CARGO_VENDOR_DIR}
.for crate in ${CARGO_CRATE_DEPENDS}
	${RUN}${PRINTF} '{"package":"%s","files":{}}'	\
	  $$(${DIGEST} sha256 < ${_DISTDIR}/${crate}.crate) \
	  > ${CARGO_VENDOR_DIR}/${crate}/.cargo-checksum.json
.endfor

# Legacy name
.PHONY: show-cargo-depends
show-cargo-depends: print-cargo-depends

.PHONY: print-cargo-depends
print-cargo-depends:
	${RUN}${AWK} 'BEGIN {print "# $$Net" "BSD$$"; print;}		\
		/^name = / { split($$3, a, "\""); name=a[2]; }		\
		/^version = / { split($$3, a, "\""); vers=a[2]; }	\
		/^source = / {						\
			print "CARGO_CRATE_DEPENDS+=\t" name "-" vers;	\
			}' ${WRKSRC}/Cargo.lock

DEFAULT_CARGO_ARGS=	build --offline --release -j${_MAKE_JOBS_N}
CARGO_ARGS?=		${DEFAULT_CARGO_ARGS}

.if !target(do-build)
do-build: do-cargo-build
.endif

.PHONY: do-cargo-build
do-cargo-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/cargo ${CARGO_ARGS}
