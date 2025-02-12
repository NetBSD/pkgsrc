# $NetBSD: Makefile,v 1.15 2025/02/12 06:15:59 adam Exp $

DISTNAME=	cmake_language_server-0.1.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
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

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cmake-language-server cmake-language-server-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
