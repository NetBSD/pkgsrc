# $NetBSD: Makefile,v 1.14 2026/10/29 13:47:10 adam Exp $

DISTNAME=	python_discovery-1.6.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-discovery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/python-discovery
COMMENT=	Python interpreter discovery
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=25.1:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.16.1:../../devel/py-filelock
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.6.1:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.3.4:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.14.1:../../devel/py-test-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-vermin>=1.8:../../

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
