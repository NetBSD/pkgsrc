# $NetBSD: Makefile,v 1.15 2026/11/18 07:27:07 adam Exp $

DISTNAME=	libjwt-3.6.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=benmcollins/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benmcollins/libjwt
COMMENT=	JWT C library
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	doxygen>=1.18:../../devel/doxygen

USE_LANGUAGES=		c c++
USE_TOOLS+=		bash pkg-config
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_GNUTLS=OFF

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=	test

SUBST_CLASSES+=		bashpath
SUBST_STAGE.bashpath=	pre-configure
SUBST_MESSAGE.bashpath=	Fixing path to bash.
SUBST_FILES.bashpath=	CMakeLists.txt
SUBST_SED.bashpath=	-e 's,/bin/bash,${BASH},g'

PLIST_SRC=	${PLIST_SRC_DFLT} ${WRKDIR}/PLIST.DOCS

.PHONY: doxygen-plist
post-install: doxygen-plist
doxygen-plist:
	${RM} -f ${WRKDIR}/PLIST.DOCS
	cd ${DESTDIR}${PREFIX} && \
	${FIND} share/doc/LibJWT/html -type f -print > ${WRKDIR}/PLIST.DOCS

# for tests
.include "../../devel/check/buildlink3.mk"
.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=3
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
