# $NetBSD: Makefile,v 1.17 2025/04/18 10:01:18 adam Exp $

DISTNAME=	logbook-1.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://logbook.readthedocs.io/
COMMENT=	Logging replacement for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# compression
DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
