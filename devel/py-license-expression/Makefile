# $NetBSD: Makefile,v 1.10 2025/07/27 08:35:52 adam Exp $

DISTNAME=	license_expression-30.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/license-expression/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nexB/license-expression
COMMENT=	Library to parse, compare, simplify and normalize license expressions
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-boolean.py>=4.0:../../devel/py-boolean.py

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
