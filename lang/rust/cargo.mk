# $NetBSD: cargo.mk,v 1.39 2024/10/11 12:42:10 jperkin Exp $
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

CHECK_SSP_SUPPORTED=	no

.include "../../lang/rust/rust.mk"

USE_TOOLS+=		bsdtar digest
CARGO_VENDOR_DIR=	${WRKDIR}/vendor
CARGO_WRKSRC?=		${WRKSRC}

# TODO: some Cargo.lock files include git+https sources which need to be fetched from the URL (not necessarily resolving to a crate.io url)
DISTFILES?=			${DEFAULT_DISTFILES}
.for crate in ${CARGO_CRATE_DEPENDS}
DISTFILES+=			${crate}.crate
SITES.${crate}.crate+=		-${MASTER_SITE_CRATESIO}${crate:C/-[0-9]+\.[0-9.]+.*$//}/${crate:C/^.*-([0-9]+\.[0-9.]+.*)$/\1/}/download
EXTRACT_DIR.${crate}.crate?=	${CARGO_VENDOR_DIR}
.endfor

.include "../../mk/bsd.prefs.mk"
# Triggers NetBSD ld.so bug (PR toolchain/54192)
# See Makefile for further information.
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099957
MAKE_JOBS_SAFE=	no
.endif

post-extract: cargo-vendor-crates
.PHONY: cargo-vendor-crates
cargo-vendor-crates:
	@${STEP_MSG} "Extracting local cargo crates"
	${RUN}${MKDIR} ${WRKDIR}/.cargo
	${RUN}${PRINTF} "[source.crates-io]\nreplace-with = \"vendored-sources\"\n[source.vendored-sources]\ndirectory = \"${CARGO_VENDOR_DIR}\"\n" > ${WRKDIR}/.cargo/config.toml
	${RUN}${MKDIR} ${CARGO_VENDOR_DIR}
.for crate in ${CARGO_CRATE_DEPENDS}
	${RUN}${PRINTF} '{"package":"%s","files":{}}'	\
	  `${DIGEST} sha256 < ${_DISTDIR}/${crate}.crate` \
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
			}' ${CARGO_WRKSRC}/Cargo.lock

.if ${RUST_TYPE} == "native"
CARGO=			cargo
.else
CARGO=			${PREFIX}/bin/cargo
.endif
DEFAULT_CARGO_ARGS=	--offline -j${_MAKE_JOBS_N}	\
			  ${CARGO_NO_DEFAULT_FEATURES:M[yY][eE][sS]:C/[yY][eE][sS]/--no-default-features/}	\
			  ${CARGO_FEATURES:C/.*/--features/W}	\
			  ${CARGO_FEATURES:S/ /,/Wg}
CARGO_ARGS?=		build --release ${DEFAULT_CARGO_ARGS}
CARGO_INSTALL_ARGS?=	install --path . --root ${DESTDIR}${PREFIX} ${DEFAULT_CARGO_ARGS}

MAKE_ENV+=		RUSTFLAGS=${RUSTFLAGS:Q}
ALL_ENV+=		CARGO_HOME=${WRKDIR}

.if !target(do-build)
do-build: do-cargo-build
.endif

.PHONY: do-cargo-build
do-cargo-build:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} ${CARGO_ARGS}

.if !target(do-install) && ${GNU_CONFIGURE:Uno:tl} == no
do-install: do-cargo-install
.endif

.PHONY: do-cargo-install
do-cargo-install:
	${RUN} cd ${CARGO_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CARGO} ${CARGO_INSTALL_ARGS}
	# remove files cargo uses for tracking installations
	${RM} -f ${DESTDIR}${PREFIX}/.crates.toml
	${RM} -f ${DESTDIR}${PREFIX}/.crates2.json

.if ${OPSYS} == "Darwin"
.PHONY: do-cargo-post-install-darwin-fix-rpath
post-install: do-cargo-post-install-darwin-fix-rpath
do-cargo-post-install-darwin-fix-rpath:
	${RUN} cd ${DESTDIR};								\
	for i in $$(${FIND} .${PREFIX}/lib -name '*.so' | ${SED} -e 's|^\./||'); do	\
	  install_name_tool -id /$$i $$i;						\
	done
.endif
