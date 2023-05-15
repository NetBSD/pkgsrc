# $NetBSD: Makefile,v 1.6 2023/05/15 09:54:18 adam Exp $

DISTNAME=	poetry_core-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poetry-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://python-poetry.org/
COMMENT=	Poetry PEP 517 build backend
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
