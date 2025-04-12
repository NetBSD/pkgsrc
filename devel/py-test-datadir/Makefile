# $NetBSD: Makefile,v 1.4 2025/04/12 21:10:56 adam Exp $

DISTNAME=	pytest_datadir-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-datadir/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/gabrielcnr/pytest-datadir
COMMENT=	Pytest plugin for test data directories and files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
