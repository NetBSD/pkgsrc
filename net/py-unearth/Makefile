# $NetBSD: Makefile,v 1.31 2026/10/28 08:32:53 adam Exp $

DISTNAME=	unearth-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unearth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/frostming/unearth
COMMENT=	Utility to fetch and download python packages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-httpx2>=2.0:../../www/py-httpx2
DEPENDS+=	${PYPKGPREFIX}-packaging>=20:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=2.1.2:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-wsgi-adapter>=0.4.1:../../www/py-requests-wsgi-adapter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver>=1.0.4:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.12.0:../../devel/py-test-mock

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	unearth

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 313
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0.9.0:../../security/py-trustme
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
