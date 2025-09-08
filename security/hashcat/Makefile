# $NetBSD: Makefile,v 1.8 2025/09/08 15:03:40 adam Exp $

DISTNAME=	hashcat-7.1.2
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
MAKE_ENV+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	SHARED=1
MAKE_ENV+=	USE_SYSTEM_XXHASH=1
MAKE_ENV+=	USE_SYSTEM_ZLIB=1
.if ${MACHINE_ARCH} == "aarch64"
MAKE_ENV+=	IS_ARM=1
.else
MAKE_ENV+=	IS_ARM=0
.endif

.include "../../mk/bsd.fast.prefs.mk"
# see include/common.h
BROKEN_ON_PLATFORM+=	${BIGENDIANPLATFORMS}

CARGO_WRKSRC=	${WRKSRC}/Rust/generic_hash
.include "cargo-depends.mk"

REPLACE_PERL=	tools/*.pl
REPLACE_PYTHON=	tools/*.py

# Define custom 'do-build' and 'do-install', so both cargo and regular targets
# do not collide.
do-build: do-cargo-build
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

do-install:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
		-f ${MAKE_FILE} ${INSTALL_TARGET}

.include "../../mk/bsd.prefs.mk"

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/hashcat/sort_r.h.orig
.if ${OPSYS} == "Darwin"
	${RUN} cd ${DESTDIR};						\
	for i in $$(${FIND} .${PREFIX}/share/hashcat -name '*.so' |	\
		${SED} -e 's|^\./||'); do				\
		install_name_tool -id /$$i $$i;				\
	done
.endif

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
