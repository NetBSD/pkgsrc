# $NetBSD: Makefile,v 1.111 2019/08/11 13:21:23 wiz Exp $

DISTNAME=	rustc-1.36.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		bash ggrep gmake perl:build pkg-config

# The NetBSD bootstraps are built for NetBSD 8 (because rust doesn't
# build on 7).  Mark earlier versions as broken.
BROKEN_ON_PLATFORM+=	NetBSD-[1-7].*-*

CHECK_PORTABILITY_SKIP+=vendor/openssl-src/openssl/.travis-create-release.sh

HAS_CONFIGURE=		yes
PYTHON_FOR_BUILD_ONLY=	yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	src/bootstrap/configure.py
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--python=${PYTHONBIN}
CONFIGURE_ARGS+=	--release-channel=stable
#CONFIGURE_ARGS+=	--enable-local-rust
CONFIGURE_ARGS+=	--local-rust-root=${RUST_BOOTSTRAP_PATH}
CONFIGURE_ARGS+=	--enable-extended	# Build and install cargo too.
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--disable-codegen-tests
CONFIGURE_ARGS+=	--disable-dist-src
CONFIGURE_ARGS+=	--disable-llvm-static-stdcpp
CONFIGURE_ARGS+=	--disable-ninja
# XXX: to be enabled in the future
#CONFIGURE_ARGS+=	--jemalloc-root=${BUILDLINK_PREFIX.jemalloc}/lib

# Use "dist" build target for cross compile of bootstrap
#BUILD_TARGET=		dist
BUILD_TARGET=		build

# The gcc-wrap / c++-wrap script takes CROSS_ROOT environment variable
# to do a cross-build.  The wrapper script assumes dest/ and tools/
# as a result of a cross-build as subdirectories of this root
#CROSS_ROOT=		/u/evbarm-armv7hf
#CROSS_ROOT=		/u/sparc64
#CROSS_ROOT=		/u/macppc
#CROSS_ROOT=		/u/evbarm64
#MAKE_ENV+=		CROSS_ROOT=${CROSS_ROOT}

# The GNU cross target designation
#GNU_CROSS_TARGET=	armv7--netbsdelf-eabihf
#GNU_CROSS_TARGET=	sparc64--netbsd
#GNU_CROSS_TARGET=	powerpc--netbsd
#GNU_CROSS_TARGET=	aarch64--netbsd
#MAKE_ENV+=		GNU_CROSS_TARGET=${GNU_CROSS_TARGET}

# To cross-build rust, you need to specify
# the ultimate target to built for, as well as the
# host the compiler is supposed to run on.
# Rust's target designation
#TARGET= 		armv7-unknown-netbsd-eabihf
#TARGET= 	 	sparc64-unknown-netbsd
#TARGET= 		powerpc-unknown-netbsd
#TARGET= 		aarch64-unknown-netbsd
#SCRIPTS=		${WRKDIR}/scripts
#CONFIGURE_ARGS+=	--host=${TARGET}
#CONFIGURE_ARGS+=	--target=${TARGET}
# for gcc as target compiler:
#CONFIGURE_ARGS+=	--set=target.${TARGET}.cc=${SCRIPTS}/gcc-wrap
#CONFIGURE_ARGS+=	--set=target.${TARGET}.cxx=${SCRIPTS}/c++-wrap
#CONFIGURE_ARGS+=	--set=target.${TARGET}.linker=${SCRIPTS}/gcc-wrap
# for clang as target compiler:
#CONFIGURE_ARGS+=	--set=target.${TARGET}.cc=${SCRIPTS}/clang-wrap
#CONFIGURE_ARGS+=	--set=target.${TARGET}.cxx=${SCRIPTS}/clang++-wrap
#CONFIGURE_ARGS+=	--set=target.${TARGET}.linker=${SCRIPTS}/clang-wrap
# common:
#CONFIGURE_ARGS+=	--set=target.${TARGET}.ar=${CROSS_ROOT}/tools/bin/${GNU_CROSS_TARGET}-ar

# May be required when cross-building on NetBSD
#MAKE_ENV+=		OPENSSL_DIR=/usr

# Getting RPATH with $ORIGIN into bootstrap may be troublesome, so
# uncommenting the LD_LIBRARY_PATH setting may be required to run
# the bootstrap
PKGSRC_MAKE_ENV+=	LD_LIBRARY_PATH=${RUST_BOOTSTRAP_PATH:Q}/lib

.if !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
# Bootstrapping on NetBSD/powerpc requires no debug-info from rustc
# (both for amd64->powerpc built and powerpc->powerpc built bootstrap bits)
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-debuginfo-tests
CONFIGURE_ARGS+=	--disable-debug-assertions
CONFIGURE_ARGS+=	--disable-debuginfo
CONFIGURE_ARGS+=	--disable-debuginfo-lines
CONFIGURE_ARGS+=	--disable-debuginfo-only-std
CONFIGURE_ARGS+=	--disable-debuginfo-tools
.endif

# This should allow us to perform "offline" builds (so cargo doesn't fetch
# dependencies during the build stage) but this isn't hooked up yet.
CONFIGURE_ARGS+=	--enable-vendor

# cargo defaults to using the number of available CPUs
MAKE_ENV+=		CARGO_BUILD_JOBS=${MAKE_JOBS:U1}

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

UNLIMIT_RESOURCES+=	cputime

TEST_TARGET=	check

# bin/* lib/*, but names vary
CHECK_RELRO_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no

CHECK_PORTABILITY_SKIP+=	src/vendor/openssl-src/openssl/.travis-create-release.sh

.include "../../mk/bsd.prefs.mk"

#
# Under NetBSD, do not use DT_RUNPATH
#
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags

.PHONY: pre-build-fix
#
# Rust unfortunately requires itself to build.  On platforms which aren't
# supported by upstream (where they offer binary bootstraps), or where we do
# not trust random binaries from the Internet, we need to build and provide our
# own bootstrap.  See the stage0-bootstrap below for more details.
#
DISTFILES:=		${DEFAULT_DISTFILES}
RUST_STAGE0_VER=	1.35.0
#
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH:=		i686-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH:=		x86_64-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH:=		i686-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH:=		x86_64-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MSunOS-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH:=		x86_64-sun-solaris
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
SITES.${RUST_STAGE0}=	https://us-east.manta.joyent.com/pkgsrc/public/pkg-bootstraps/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0}
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH:=		i686-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH:=		x86_64-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH=		i686-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
# Setting this changes it for every distfile, which doesn't match what is
# currently in distinfo.
#DIST_SUBDIR=		${PKGNAME}
# For atomic ops
CFLAGS+=		-march=i586
pre-build-fix:
	${TOOLS_PLATFORM.paxctl} +am ${WRKDIR}/rust-bootstrap/bin/cargo
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH=		x86_64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH=		powerpc-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.36.0
RUST_ARCH=		aarch64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64) || make(distinfo) || make (makesum) || make(mdi)
RUST_STAGE0_VER=	1.35.0
RUST_ARCH=		sparc64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
pre-build-fix:
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-earmv7hf) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=		armv7-unknown-netbsd-eabihf
RUST_STAGE0_VER=	1.35.0
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
SITES.${RUST_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
SITES.${RUST_STD_STAGE0}=	${MASTER_SITE_LOCAL:=rust/}
pre-build-fix:
.endif

# You may override RUST_BOOTSTRAP_PATH and RUST_ARCH in mk.conf if you have a local bootstrap compiler.
.if !defined(RUST_ARCH) && !defined(RUST_BOOTSTRAP_PATH)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.else
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-bootstrap
.endif

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum
.endif

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath=	src/bootstrap/bin/rustc.rs
SUBST_VARS.rpath=	PREFIX

post-extract:
	set -e;									\
	if ${TEST} -e ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/install.sh	\
	  -a ! -e ${RUST_BOOTSTRAP_PATH}/bin/rustc; then \
		cd ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH};		\
		${TOOLS_BASH} ./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
		cd ${WRKDIR}/rust-std-${RUST_STAGE0_VER}-${RUST_ARCH};		\
		${TOOLS_BASH} ./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
	fi
# patch(1) in NetBSD does not handle .cargo-checksum.json like long width file.
	${CP} ${WRKSRC}/vendor/rand/.cargo-checksum.json \
	      ${WRKSRC}/vendor/rand/.cargo-checksum.json.orig
	${SED} -e 's/1e732c2e3b4bd1561f11e0979bf9d20669a96eae7afe0deff9dfbb980ee47bf1/bc03f2345d7cfa7000f9da817120b6afa073359789c21a9a790ebd8676c50cca/' ${WRKSRC}/vendor/rand/.cargo-checksum.json.orig > ${WRKSRC}/vendor/rand/.cargo-checksum.json
	${CP} ${WRKSRC}/vendor/libc/.cargo-checksum.json \
		${WRKSRC}/vendor/libc/.cargo-checksum.json.orig
	${SED} -e 's/0c6d148d84f2fa9feb86b464d30af9c52322553bf321ae4fe27184d274ccbe21/27dae4ec77f317c74e2c205658bcc8220c512f751802b754b07770c16e420dd1/' ${WRKSRC}/vendor/libc/.cargo-checksum.json.orig > ${WRKSRC}/vendor/libc/.cargo-checksum.json
	${CP} ${WRKSRC}/vendor/backtrace-sys/.cargo-checksum.json \
	      ${WRKSRC}/vendor/backtrace-sys/.cargo-checksum.json.orig
	${SED} -e 's/59763fc255248b54fba5d0761d61093a73d51fa4cb400b0df1b5f339b9c2f48a/ba66d192421fd536ceddb50616c4c4aea06f4e39450eb0bc2bbbaed0b1e684c1/' ${WRKSRC}/vendor/backtrace-sys/.cargo-checksum.json.orig > ${WRKSRC}/vendor/backtrace-sys/.cargo-checksum.json
.if ${OPSYS} == "NetBSD"
	SDIR=${WRKDIR}/scripts; \
	${MKDIR} $${SDIR}; \
	cd $${SDIR}; \
	${RM} -f c++-wrap; \
	${RM} -f clang++-wrap; \
	${RM} -f clang-wrap; \
	${CP} ${.CURDIR}/files/gcc-wrap .; \
	${CHMOD} +x gcc-wrap; \
	${LN} -s gcc-wrap c++-wrap; \
	${LN} -s gcc-wrap clang++-wrap; \
	${LN} -s gcc-wrap clang-wrap
.endif

.if ${OPSYS} == "FreeBSD"
MAKE_ENV+=		OPENSSL_DIR=${SSLBASE}
.endif

.if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mclang) && !exists(/lib/libgcc_s.so)
BUILDLINK_TRANSFORM+=	rm:-lgcc_s
MAKE_ENV+=		PKGSRC_HAVE_LIBCPP=yes
.endif

pre-build: pre-build-fix
.if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mclang) && !exists(/lib/libgcc_s.so)
	cp ${FILESDIR}/libgcc_s.so.1 ${RUST_BOOTSTRAP_PATH}/lib/.
.endif

do-build:
	cd ${WRKSRC} \
	&& ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} ./x.py -v ${BUILD_TARGET} -j ${MAKE_JOBS:U1}

do-install:
	cd ${WRKSRC} \
	&& ${SETENV} ${MAKE_ENV} ${INSTALL_ENV} \
		${PYTHONBIN} ./x.py -v install -j ${MAKE_JOBS:U1}

GENERATE_PLIST+=find ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
		sed 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

.if ${OPSYS} == "Darwin"
LDFLAGS+=		-headerpad_max_install_names

.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for bin in cargo-miri clippy-driver miri rls rustc rustdoc
	otool -XL ${DESTDIR}${PREFIX}/bin/${bin}			\
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
		    ${DESTDIR}${PREFIX}/bin/${bin};			\
	done
.  endfor
.  for libdir in lib lib/rustlib/${RUST_ARCH}/lib lib/rustlib/${RUST_ARCH}/codegen-backends
	for f in ${DESTDIR}${PREFIX}/${libdir}/lib*.dylib; do		\
		[ ! -f $$f ] && continue;				\
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
		otool -XL $$f | grep '@rpath' | while read rpath rest; do \
			install_name_tool -change $$rpath \
			    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
			    $$f;					\
		done;							\
	done
.  endfor
.endif

#
# Create a relocatable stage2 bootstrap from the bits we just built that can be
# used to build the next version of rust.  Currently only tested on SmartOS.
#
BOOTSTRAP_TMPDIR=	${WRKDIR}/${PKGNAME_NOREV}-${RUST_ARCH}
USE_TOOLS+=		gtar

# The NetBSD part is so far untested, because I could not convince
# the rust build to use the gcc wrapper when building natively,
# so that I could get a placeholder in the RPATH, because chrpath
# cannot extend the length of the RPATH...

stage0-bootstrap: install
	${RM} -rf ${BOOTSTRAP_TMPDIR}
	${MKDIR} ${BOOTSTRAP_TMPDIR}
.if ${OPSYS} == "NetBSD"
	(cd ${BOOTSTRAP_TMPDIR}; \
	DISTDIR=${WRKSRC}/bild/dist; \
	VER_ARCH=${PKGVERSION}-${RUST_ARCH}; \
	RUSTC=rustc-$${VER_ARCH}; \
	RUSTC_FILE=$${RUSTC}.tar.gz; \
	RUST_STD=rust-std-$${VER_ARCH}; \
	RUST_STD_FILE=$${RUST_STD}.tar.gz; \
	${GTAR} -xzf $${DISTDIR}/$${RUSTC_FILE}; \
		(cd ${RUSTC}; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN/../lib'; \
	for f in rls-preview/bin/rls rustc/bin/rustc rustc/bin/rustdoc; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN'; \
	for f in rustc/lib/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done; \
	RPATH='/usr/pkg/lib:/lib:/usr/lib:$$ORIGIN:$$ORIGIN/../../..'; \
	for f in rustc/lib/rustlib/*/*/*.so*; do \
		chrpath -r $$RPATH $$f; \
	done;); \
	${GTAR} -czf $${RUSTC_FILE} $${RUSTC}; \
	${CP} $${DISTDIR}/$${RUST_STD_FILE} .; \
	${ECHO} "Fixed stage0 bootstrap in ${BOOTSTRAP_TMPDIR}:"; \
	${ECHO} "$${RUSTC_FILE}"; \
	${ECHO} "$${RUST_STD_FILE}"; \
	)
.endif
.if ${OS_VARIANT} == "SmartOS"
	${CP} -R ${DESTDIR}/${PREFIX}/bin ${BOOTSTRAP_TMPDIR}/
	${CP} -R ${DESTDIR}/${PREFIX}/lib ${BOOTSTRAP_TMPDIR}/
	${MKDIR} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc
	for lib in libgcc_s.so.1 libssp.so.0 libstdc++.so.6; do \
		${CP} `${PKG_CC} -print-file-name=$${lib}` \
		    ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done
	for lib in libcrypto.so.1.0.0 libcurl.so.4 libhttp_parser.so.2 \
		   libiconv.so.2 libidn2.so.0 libintl.so.8 liblber-2.4.so.2 \
		   libldap-2.4.so.2 libnghttp2.so.14 libsasl2.so.3 libLLVM-8.so \
		   libssh2.so.1 libssl.so.1.0.0 libunistring.so.2 libz.so.1; do \
		${CP} ${PREFIX}/lib/$${lib} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/bin/{cargo,rls,rustc,rustdoc}; do \
		/usr/bin/elfedit -e 'dyn:runpath $$ORIGIN/../lib:$$ORIGIN/../lib/pkgsrc' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/*.so*; do \
		/usr/bin/elfedit -e 'dyn:runpath $$ORIGIN' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/*.so*; do \
		/usr/bin/elfedit -e 'dyn:runpath $$ORIGIN:$$ORIGIN/pkgsrc' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/rustlib/${RUST_ARCH}/*/*.so*; do \
		/usr/bin/elfedit -e 'dyn:runpath $$ORIGIN:$$ORIGIN/../../..:$$ORIGIN/../../../pkgsrc' $$f; \
	done
	(cd ${WRKDIR}; \
	 ${GTAR} -zcf ${PKGNAME_NOREV}-${RUST_ARCH}.tar.gz ${PKGNAME_NOREV}-${RUST_ARCH})
.endif

.include "options.mk"

# These dependencies currently use the bundled sources as they require
# development features not yet available in released versions.
#
#.include "../../devel/libgit2/buildlink3.mk"
#.include "../../security/libssh2/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"
#.include "../../www/http-parser/buildlink3.mk"

#.include "../../devel/jemalloc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
