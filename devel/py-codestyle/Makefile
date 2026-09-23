# $NetBSD: Makefile,v 1.20 2026/09/23 12:08:06 adam Exp $

DISTNAME=	pycodestyle-2.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycodestyle/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://pycodestyle.pycqa.org/en/latest/
COMMENT=	Python style guide checker
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pycodestyle

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
