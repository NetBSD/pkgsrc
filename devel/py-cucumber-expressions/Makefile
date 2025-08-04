# $NetBSD: Makefile,v 1.1 2025/08/04 08:00:33 wiz Exp $

DISTNAME=	cucumber_expressions-18.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cucumber_expressions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/cucumber_expressions/
COMMENT=	Simpler alternative to Regular Expressions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

# as of 18.0.1:
# 5 errors
# because of missing testdata in pypi distfile, with testdata:
# 188 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
