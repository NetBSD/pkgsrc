# $NetBSD: Makefile,v 1.2 2025/07/28 16:49:17 dkazankov Exp $

DISTNAME=	railroad-diagrams-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/railroad-diagrams/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/tabatkins/railroad-diagrams
COMMENT=	Railroad-Diagram Generator, Python Version
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-flake8>=6.0.0:../../devel/py-flake8

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
