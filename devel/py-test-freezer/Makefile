# $NetBSD: Makefile,v 1.1 2023/11/28 17:05:27 adam Exp $

DISTNAME=	pytest_freezer-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-freezer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-freezer
COMMENT=	Pytest plugin providing a fixture interface for freezegun
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.0:../../devel/py-freezegun
DEPENDS+=	${PYPKGPREFIX}-test>=3.6:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
