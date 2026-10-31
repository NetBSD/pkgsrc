# $NetBSD: Makefile,v 1.9 2026/10/31 17:12:20 adam Exp $

DISTNAME=	hashcat-8.0.0
CATEGORIES=	security
MASTER_SITES=	https://hashcat.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hashcat.net/
COMMENT=	World's fastest and most advanced password recovery utility
LICENSE=	mit

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake gsed perl:run

BUILD_TARGET=	hashcat
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	SHARED=1
MAKE_ENV+=	USE_SYSTEM_OPENCL=1
MAKE_ENV+=	USE_SYSTEM_XXHASH=1
MAKE_ENV+=	USE_SYSTEM_ZLIB=1

.if ${MACHINE_ARCH} == "aarch64"
MAKE_ENV+=	IS_ARM=1
.else
MAKE_ENV+=	IS_ARM=0
.endif

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "powerpc64"
MAKE_ENV+=	IS_PPC=1
.else
MAKE_ENV+=	IS_PPC=0
.endif

.include "../../mk/bsd.fast.prefs.mk"
# see include/common.h
BROKEN_ON_PLATFORM+=	${BIGENDIANPLATFORMS}

#CARGO_WRKSRC=	${WRKSRC}/Rust/bridges/dynamic_hash
#CARGO_WRKSRC=	${WRKSRC}/Rust/bridges/generic_hash
#CARGO_WRKSRC=	${WRKSRC}/Rust/feeds/random

.include "cargo-depends.mk"

REPLACE_PERL=		tools/*.pl
REPLACE_PYTHON+=	extra/fpga/zc706-sdboot/make_bootbin.py
REPLACE_PYTHON+=	tools/*.py

# Define custom 'do-build' and 'do-install', so both cargo and regular targets
# do not collide.
do-build:
.for cargo_dir in bridges/dynamic_hash bridges/generic_hash feeds/random
	cd ${WRKSRC}/Rust/${cargo_dir} && ${SETENV} ${MAKE_ENV} ${CARGO} ${CARGO_ARGS}
.endfor
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

do-install:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
		-f ${MAKE_FILE} ${INSTALL_TARGET}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install:
	${RUN} \
	install_name_tool -id ${PREFIX}/lib/libhashcat.8.dylib ${DESTDIR}${PREFIX}/lib/libhashcat.8.dylib; \
	install_name_tool -change @rpath/libhashcat.8.dylib ${PREFIX}/lib/libhashcat.8.dylib ${DESTDIR}${PREFIX}/bin/hashcat; \
	cd ${DESTDIR}; \
	for i in $$(${FIND} .${PREFIX}/share/hashcat -name '*.so' | ${SED} -e 's|^\./||'); do \
		install_name_tool -id /$$i $$i; \
		install_name_tool -change @rpath/libhashcat.8.dylib ${PREFIX}/lib/libhashcat.8.dylib $$i; \
	done
.endif

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
.include "../../parallel/opencl-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
