# $NetBSD: Makefile,v 1.8 2025/04/13 12:30:44 wiz Exp $

DISTNAME=	license_expression-30.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
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
