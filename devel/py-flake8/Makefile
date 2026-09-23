# $NetBSD: Makefile,v 1.55 2026/09/23 12:12:01 adam Exp $

DISTNAME=	flake8-7.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycqa/flake8
COMMENT=	Modular source code checker for Python programs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.15.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-flakes>=4.0.0:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.7.0:../../devel/py-mccabe

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	flake8

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
