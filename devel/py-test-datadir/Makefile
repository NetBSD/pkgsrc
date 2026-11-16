# $NetBSD: Makefile,v 1.6 2026/11/16 15:57:02 adam Exp $

DISTNAME=	pytest_datadir-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-datadir/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gabrielcnr/pytest-datadir
COMMENT=	Pytest plugin for test data directories and files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
