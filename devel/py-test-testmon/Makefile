# $NetBSD: Makefile,v 1.17 2025/11/17 13:51:32 adam Exp $

DISTNAME=	pytest_testmon-2.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-testmon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tarpas/pytest-testmon
COMMENT=	Selects tests affected by changed files and methods
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-coverage>=6:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-test>=5:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
