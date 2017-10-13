# $NetBSD: Makefile,v 1.14 2017/10/13 12:42:12 ryoon Exp $

DISTNAME=	rustc-1.20.0-src
PKGNAME=	${DISTNAME:S/rustc/rust/:S/-src//}
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		bash gmake perl:build pkg-config

UNLIMIT_RESOURCES+=	cputime

TEST_TARGET=	check

# bin/* lib/*, but names vary
CHECK_RELRO_SUPPORTED=	no

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
RUST_STAGE0_VER=	1.19.0
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
#.if !empty(MACHINE_PLATFORM:MSunOS-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
#RUST_ARCH:=		x86_64-sun-solaris
#RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
#SITES.${RUST_STAGE0}=	https://us-east.manta.joyent.com/pkgsrc/public/pkg-bootstraps/
#DISTFILES:=		${DISTFILES} ${RUST_STAGE0}
#.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make (makesum) || make(mdi)
RUST_ARCH=		x86_64-unknown-netbsd
RUST_STAGE0:=		rust-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
RUST_STD_STAGE0:=	rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}.tar.gz
DISTFILES:=		${DISTFILES} ${RUST_STAGE0} ${RUST_STD_STAGE0}
.endif

.if !defined(RUST_ARCH)
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

OPSYSVARS+=		SOEXT
SOEXT.Darwin=		dylib
SOEXT.*=		so

RUST_VERHASH=		63283ac5
PLIST_SUBST+=		RUST_ARCH=${RUST_ARCH:Q}
PLIST_SUBST+=		RUST_VERHASH=${RUST_VERHASH:Q}
PLIST_SUBST+=		SOEXT=${SOEXT:Q}
PRINT_PLIST_AWK+=	{ gsub(/${RUST_ARCH}/, "$${RUST_ARCH}") }
PRINT_PLIST_AWK+=	{ gsub(/${RUST_VERHASH}/, "$${RUST_VERHASH}") }
PRINT_PLIST_AWK+=	{ gsub(/\.${SOEXT}/, ".$${SOEXT}") }

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		grep>=0:../../textproc/grep
BUILD_DEPENDS+=		coreutils>=0:../../sysutils/coreutils
TOOLS_PATH.grep=	${PREFIX}/bin/ggrep
TOOLS_CREATE+=		md5sum
TOOLS_PATH.md5sum=	${PREFIX}/bin/gmd5sum

SUBST_CLASSES+=		ranlib
SUBST_STAGE.ranlib=	post-patch
SUBST_FILES.ranlib=	mk/rt.mk
SUBST_SED.ranlib=	-e 's,RANLIB=.* \\,RANLIB="true" \\,g'
.endif

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	post-patch
SUBST_FILES.rpath=	src/bootstrap/bin/rustc.rs
SUBST_VARS.rpath=	PREFIX

post-extract:
	${MV} ${WRKDIR}/rust-std-${RUST_STAGE0_VER}-${RUST_ARCH}/rust-std-${RUST_ARCH}/lib/rustlib/${RUST_ARCH} \
		${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/rustc/lib/rustlib

RUSTC=			${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/rustc/bin/rustc
CARGO=			${WRKDIR}/rust-${RUST_STAGE0_VER}-${RUST_ARCH}/cargo/bin/cargo

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-configure
SUBST_FILES.config+=	config.toml
SUBST_VARS.config+=	RUSTC CARGO PREFIX PYTHONBIN RUST_ARCH

do-configure:
	${CP} ${FILESDIR}/config.toml ${WRKSRC}/config.toml

do-build:
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
		${PYTHONBIN} ./x.py dist

do-install:
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} ${INSTALL_ENV} \
		${PYTHONBIN} ./x.py install

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/install.log
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
BOOTSTRAP_TMPDIR=	${WRKDIR}/${PKGNAME}-${RUST_ARCH}/rustc
USE_TOOLS+=		gtar

stage0-bootstrap: install
	${MKDIR} ${BOOTSTRAP_TMPDIR}
	${CP} -R ${DESTDIR}/${PREFIX}/bin ${BOOTSTRAP_TMPDIR}/
	${CP} -R ${DESTDIR}/${PREFIX}/lib ${BOOTSTRAP_TMPDIR}/
.if ${OS_VARIANT} == "SmartOS"
	for lib in libgcc_s.so.1 libssp.so.0 libstdc++.so.6; do \
		${CP} `${PKG_CC} -print-file-name=$${lib}` \
		    ${BOOTSTRAP_TMPDIR}/lib/; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/bin/rust{c,doc}; do \
		/usr/bin/elfedit -e 'dyn:runpath $$ORIGIN/../lib' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/*.so*; do \
		/usr/bin/elfedit -e 'dyn:runpath $$ORIGIN' $$f; \
	done
	for f in ${BOOTSTRAP_TMPDIR}/lib/rustlib/${RUST_ARCH}/lib/*.so*; do \
		/usr/bin/elfedit -e 'dyn:runpath $$ORIGIN:$$ORIGIN/../../..' $$f; \
	done
.endif
	(cd ${WRKDIR}; \
	 ${GTAR} -zcf ${PKGNAME}-${RUST_ARCH}.tar.gz ${PKGNAME}-${RUST_ARCH})

.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.llvm+=  llvm>=4.0.1nb1
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
