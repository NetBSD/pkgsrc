# $NetBSD: Makefile,v 1.8 2023/05/05 09:52:24 wiz Exp $

DISTNAME=	cmake-language-server-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmake-language-server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/regen100/cmake-language-server
COMMENT=	CMake Language Server Protocol Implementation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-pygls>=1.0:../../lang/py-pygls
TEST_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-datadir>=1.4.1:../../devel/py-test-datadir
#TEST_DEPENDS+=	${PYPKGPREFIX}-cmakelang>=0.6.13:../../devel/py-cmakelang

PYTHON_VERSIONS_INCOMPATIBLE=	27

# only for tests
USE_LANGUAGES=	c c++

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cmake-language-server cmake-language-server-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
