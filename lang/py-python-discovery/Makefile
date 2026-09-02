# $NetBSD: Makefile,v 1.10 2026/09/02 14:14:54 adam Exp $

DISTNAME=	python_discovery-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-discovery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/python-discovery
COMMENT=	Python interpreter discovery
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.15.4:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.5.4:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.1:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
