# $NetBSD: Makefile,v 1.49 2018/08/22 09:45:22 wiz Exp $

DISTNAME=	rustc-1.28.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake perl:build pkg-config
# For internal llvm
BUILD_DEPENDS+=		cmake-[0-9]*:../../devel/cmake

HAS_CONFIGURE=		yes
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
CONFIGURE_ARGS.SunOS+=	--disable-jemalloc

# This should allow us to perform "offline" builds (so cargo doesn't fetch
# dependencies during the build stage) but this isn't hooked up yet.
CONFIGURE_ARGS+=	--enable-vendor

# cargo defaults to using the number of available CPUs
MAKE_ENV+=		CARGO_BUILD_JOBS=${MAKE_JOBS:U1}

UNLIMIT_RESOURCES+=	cputime

PYTHON_VERSIONS_ACCEPTED=	27

TEST_TARGET=	check

# bin/* lib/*, but names vary
CHECK_RELRO_SUPPORTED=	no
CHECK_SSP_SUPPORTED=	no

# Required for LLVM (-std=c++11)
GCC_REQD+=	4.8

.include "../../mk/bsd.prefs.mk"

#
# Under NetBSD, do not use DT_RUNPATH
#
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Wl,--enable-new-dtags

#
# Rust unfortunately requires itself to build.  On platforms which aren't
# supported by upstream (where they offer binary bootstraps), or where we do
# not trust random binaries from the Internet, we need to build and provide our
# own bootstrap.  See the stage0-bootstrap below for more details.
#
DISTFILES:=		${DEFAULT_DISTFILES}
RUST_STAGE0_VER=	1.27.2
#
.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH:=		i686-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH:=		x86_64-apple-darwin
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH:=		i686-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH:=		x86_64-unknown-linux-gnu
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MSunOS-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH:=		x86_64-sun-solaris
RUST_STAGE0_VER=	1.28.0
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
SITES.${RUST_STAGE0}=	https://us-east.manta.joyent.com/pkgsrc/public/pkg-bootstraps/
DISTFILES:=		${DISTFILES} ${RUST_STAGE0}
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH:=		i686-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH:=		x86_64-unknown-freebsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=		i686-unknown-netbsd
RUST_STAGE0_VER=	1.28.0
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
# Do not trust ryoon@.
SITES.${RUST_STAGE0}=	https://deuterium.ryoon.net/pub/rust/
SITES.${RUST_STD_STAGE0}=	https://deuterium.ryoon.net/pub/rust/
#DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
# Setting this changes it for every distfile, which doesn't match what is
# currently in distinfo.
#DIST_SUBDIR=		${PKGNAME}
# For atomic ops
CFLAGS+=		-march=i586
pre-build:
	${TOOLS_PLATFORM.paxctl} +am ${WRKDIR}/rust-bootstrap/bin/cargo
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=		x86_64-unknown-netbsd
RUST_STAGE0_VER=	1.28.0
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif

# You may override RUST_BOOTSTRAP_PATH and RUST_ARCH in mk.conf if you have a local bootstrap compiler.
.if !defined(RUST_ARCH) && !defined(RUST_BOOTSTRAP_PATH)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.else
RUST_BOOTSTRAP_PATH?=	${WRKDIR}/rust-bootstrap
.endif

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		grep>=0:../../textproc/grep
BUILD_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
TOOLS_PATH.grep=	${PREFIX}/bin/ggrep
TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum
.endif

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_FILES.rpath=	src/bootstrap/bin/rustc.rs
SUBST_VARS.rpath=	PREFIX

post-extract:
	set -e;									\
	if test -e ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/install.sh	\
	  -a ! -e ${RUST_BOOTSTRAP_PATH}/bin/rustc; then \
		cd ${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH};		\
		${TOOLS_BASH} ./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
		cd ${WRKDIR}/rust-std-${RUST_STAGE0_VER}-${RUST_ARCH};		\
		${TOOLS_BASH} ./install.sh --prefix=${RUST_BOOTSTRAP_PATH};	\
	fi
# patch(1) in NetBSD does not handle .cargo-checksum.json like long width file.
	cat ${WRKSRC}/src/vendor/libc/.cargo-checksum.json | \
		${SED} -e 's/2613f2912a9e8f3485debba424437608433b4e1c8b9050176ef975efdf4a412e/52431d3cc74033804febaa303d028811504c07e2b9b83ec7287d9ee159bf35fe/' > \
		${WRKSRC}/src/vendor/libc/.cargo-checksum.json.patched
	${CP} -f ${WRKSRC}/src/vendor/libc/.cargo-checksum.json.patched \
		${WRKSRC}/src/vendor/libc/.cargo-checksum.json

.if ${OPSYS} != "SunOS"
LD_LIBRARY_PATH=	${RUST_BOOTSTRAP_PATH}/lib
PKGSRC_MAKE_ENV+=	LD_LIBRARY_PATH=${LD_LIBRARY_PATH:Q}
.endif

.if ${OPSYS} == "FreeBSD"
MAKE_ENV+=		OPENSSL_DIR=${SSLBASE}
.endif

do-build:
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
		${PYTHONBIN} ./x.py -v dist

do-install:
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} ${INSTALL_ENV} \
		${PYTHONBIN} ./x.py -v install

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/install.log
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/uninstall.sh
	${RM} -rf ${DESTDIR}${PREFIX}/lib/rustlib/src

GENERATE_PLIST+= find ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
		 sed 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for bin in rustc rustdoc
	otool -XL ${DESTDIR}${PREFIX}/bin/${bin}			\
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
		    ${DESTDIR}${PREFIX}/bin/${bin};			\
	done
.  endfor
.  for libdir in lib lib/rustlib/${RUST_ARCH}/lib
	for f in ${DESTDIR}${PREFIX}/${libdir}/lib*.dylib; do		\
		[ ! -f $$f ] && continue;				\
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
		otool -XL $$f | grep '@rpath' | while read rpath rest; do \
			install_name_tool -change $$rpath \
			    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/${libdir},g'` \
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

stage0-bootstrap: install
	${RM} -rf ${BOOTSTRAP_TMPDIR}
	${MKDIR} ${BOOTSTRAP_TMPDIR}
	${CP} -R ${DESTDIR}/${PREFIX}/bin ${BOOTSTRAP_TMPDIR}/
	${CP} -R ${DESTDIR}/${PREFIX}/lib ${BOOTSTRAP_TMPDIR}/
.if ${OS_VARIANT} == "SmartOS"
	${MKDIR} ${BOOTSTRAP_TMPDIR}/lib/pkgsrc
	for lib in libgcc_s.so.1 libssp.so.0 libstdc++.so.6; do \
		${CP} `${PKG_CC} -print-file-name=$${lib}` \
		    ${BOOTSTRAP_TMPDIR}/lib/pkgsrc/; \
	done
	for lib in libcrypto.so.1.0.0 libcurl.so.4 libhttp_parser.so.2 \
		   libiconv.so.2 libidn2.so.0 libintl.so.8 liblber-2.4.so.2 \
		   libldap-2.4.so.2 libnghttp2.so.14 libsasl2.so.3 \
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
.endif
	(cd ${WRKDIR}; \
	 ${GTAR} -zcf ${PKGNAME_NOREV}-${RUST_ARCH}.tar.gz ${PKGNAME_NOREV}-${RUST_ARCH})

.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
