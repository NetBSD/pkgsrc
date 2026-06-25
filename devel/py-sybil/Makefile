# $NetBSD: Makefile,v 1.7 2026/06/25 12:46:08 adam Exp $

DISTNAME=	sybil-10.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sybil/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/simplistix/sybil
COMMENT=	Automated testing for the examples in your code and documentation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=6:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testfixtures>=11:../../devel/py-testfixtures

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
