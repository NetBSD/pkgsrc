# $NetBSD: Makefile,v 1.16 2026/08/08 15:52:29 wiz Exp $

DISTNAME=	cmake_language_server-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmake-language-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regen100/cmake-language-server
COMMENT=	CMake Language Server Protocol Implementation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-pygls>=1.1.1:../../lang/py-pygls
TEST_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-datadir>=1.4.1:../../devel/py-test-datadir
#TEST_DEPENDS+=	${PYPKGPREFIX}-cmakelang>=0.6.13:../../devel/py-cmakelang

# only for tests
USE_LANGUAGES=	c c++

PY_RENAME_BINARIES=	cmake-language-server

# as of 0.1.11nb1
# 2 failed, 7 passed, 67 warnings, 7 errors

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/cmake_language_server/server.py.orig

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
