# $NetBSD: Makefile,v 1.80 2024/05/29 16:32:25 adam Exp $

DISTNAME=		ckmame-2.1
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		https://www.nih.at/ckmame/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.nih.at/ckmame/
COMMENT=		Check ROM sets for MAME
LICENSE=		modified-bsd

# detected at configure time, and tests not run if not installed
BUILD_DEPENDS+=		${PYPKGPREFIX}-nihtest>=1.5:../../devel/py-nihtest

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
TEST_TARGET=		test

USE_CXX_FEATURES+=	c++17 filesystem

pre-configure:
	${LN} -fs ${PREFIX}/bin/nihtest-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/nihtest

.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../archivers/libarchive/buildlink3.mk"
BUILDLINK_API_DEPENDS.libzip+=	libzip>=1.8
.include "../../archivers/libzip/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
