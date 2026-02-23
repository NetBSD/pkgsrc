# $NetBSD: Makefile,v 1.14 2026/02/23 13:27:15 adam Exp $

DISTNAME=	pytest_env-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-env/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MobileDynasty/pytest-env
COMMENT=	Plugin for py.test that allows you to add environment variables
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-dotenv>=1.2.1:../../devel/py-dotenv
DEPENDS+=	${PYPKGPREFIX}-test>=9.0.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.13.4:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.15.1:../../devel/py-test-mock

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.4:../../textproc/py-tomli
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
