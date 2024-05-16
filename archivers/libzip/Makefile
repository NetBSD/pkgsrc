# $NetBSD: Makefile,v 1.70 2024/05/16 06:14:31 wiz Exp $

DISTNAME=		libzip-1.10.1
PKGREVISION=		3
CATEGORIES=		archivers devel
MASTER_SITES=		https://libzip.org/download/
MASTER_SITES+=		${MASTER_SITE_GITHUB:=nih-at/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		https://www.libzip.org/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

TEST_DEPENDS+=		${PYPKGPREFIX}-nihtest-[0-9]*:../../devel/py-nihtest

TEST_TARGET=		test
# for tests
CMAKE_ARGS+=		-DNIHTEST=${PREFIX}/bin/nihtest-${PYVERSSUFFIX}
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# for Darwin
MAKE_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
