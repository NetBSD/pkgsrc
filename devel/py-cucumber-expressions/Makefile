# $NetBSD: Makefile,v 1.4 2026/02/16 19:05:34 adam Exp $

DISTNAME=	cucumber_expressions-19.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cucumber_expressions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cucumber/cucumber-expressions
COMMENT=	Simpler alternative to Regular Expressions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.0:../../devel/py-uv-build
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.3:../../textproc/py-yaml

USE_LANGUAGES=	# none

# as of 18.0.1:
# 5 errors
# because of missing testdata in pypi distfile, with testdata:
# 188 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
