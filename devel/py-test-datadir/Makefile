# $NetBSD: Makefile,v 1.5 2025/08/13 09:50:09 adam Exp $

DISTNAME=	pytest_datadir-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-datadir/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gabrielcnr/pytest-datadir
COMMENT=	Pytest plugin for test data directories and files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
