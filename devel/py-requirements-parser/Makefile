# $NetBSD: Makefile,v 1.4 2024/04/19 04:23:30 adam Exp $

DISTNAME=	requirements_parser-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requirements-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidfischer/requirements-parser
COMMENT=	Parses Pip requirement files
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-types-setuptools>=69.1.0:../../devel/py-types-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
