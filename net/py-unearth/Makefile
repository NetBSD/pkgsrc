# $NetBSD: Makefile,v 1.19 2024/06/06 05:01:25 adam Exp $

DISTNAME=	unearth-0.15.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unearth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frostming/unearth
COMMENT=	Utility to fetch and download python packages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=2.1.2:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-wsgi-adapter>=0.4.1:../../www/py-requests-wsgi-adapter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver>=1.0.4:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.12.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0.9.0:../../security/py-trustme

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} unearth unearth-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
