# $NetBSD: Makefile,v 1.11 2023/10/26 13:33:21 adam Exp $

DISTNAME=	unearth-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unearth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frostming/unearth
COMMENT=	Utility to fetch and download python packages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=2.1.2:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-wsgi-adapter>=0.4.1:../../www/py-requests-wsgi-adapter
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver>=1.0.4:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0.9.0:../../security/py-trustme

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} unearth unearth-${PYVERSSUFFIX} || ${TRUE}

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
