# $NetBSD: Makefile,v 1.16 2021/08/09 07:05:23 sjmulder Exp $

DISTNAME=	libxlsxwriter-1.1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmcnamara/}
GITHUB_TAG=	RELEASE_${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://libxlsxwriter.github.io/
COMMENT=	C library for creating Microsoft Excel files
LICENSE=	2-clause-bsd AND original-bsd AND zlib AND mpl-2.0

PYTHON_FOR_BUILD_ONLY=	test

TEST_TARGET=	test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_TOOLS+=	gmake

.include "../../lang/python/pyversion.mk"

MAKE_ENV+=	OPT_LEVEL=
# Prefer non-bundled dependencies
MAKE_ENV+=	USE_SYSTEM_MINIZIP=1
MAKE_ENV+=	USE_STANDARD_TMPFILE=1
MAKE_ENV+=	USE_OPENSSL_MD5=1

# minizip has C++ style comments
BUILDLINK_TRANSFORM+=	rm:-ansi

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
