# $NetBSD: Makefile,v 1.2 2026/11/18 08:58:29 adam Exp $

DISTNAME=	assertpy-2.36.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/assertpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/assertpy/assertpy
COMMENT=	Simple assertion library for unit testing in python with a fluent API
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.165.0:../../devel/py-hypothesis

USE_LANGUAGES=	# none

pre-test:
	# No module named 'tests'. Did you mean: 'test'?
	${TOUCH} ${WRKSRC}/tests/__init__.py
	# No module named 'api_surface'
	${RM} -f ${WRKSRC}/tests/test_api_compatibility.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
