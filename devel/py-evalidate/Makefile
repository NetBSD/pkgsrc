# $NetBSD: Makefile,v 1.4 2026/10/29 13:45:14 adam Exp $

DISTNAME=	evalidate-2.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/evalidate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yaroslaff/evalidate
COMMENT=	Validation and secure evaluation of untrusted python expressions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=>=1.27.0:../../devel/py-hatchling

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	genfakeproducts jg

REPLACE_PYTHON+=	evalidate/__init__.py
REPLACE_PYTHON+=	evalidate/cli/jg.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
