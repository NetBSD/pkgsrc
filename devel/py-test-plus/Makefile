# $NetBSD: Makefile,v 1.1 2025/01/29 09:25:12 adam Exp $

DISTNAME=	pytest-plus-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-plus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-plus
COMMENT=	Extends pytest functionality
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-test>=7.4.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.0.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-html>0:../../devel/py-test-html

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
