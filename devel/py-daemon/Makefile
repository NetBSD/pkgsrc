# $NetBSD: Makefile,v 1.29 2024/01/12 14:26:59 adam Exp $

DISTNAME=	python-daemon-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-daemon/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://pagure.io/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.10:../../devel/py-lockfile
DEPENDS+=	${PYPKGPREFIX}-setuptools>=62.4.0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.4:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
