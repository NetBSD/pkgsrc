# $NetBSD: Makefile,v 1.14 2025/01/08 20:35:32 adam Exp $

DISTNAME=	logbook-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://logbook.readthedocs.io/
COMMENT=	Logging replacement for Python
LICENSE=	modified-bsd

WHEEL_NAME=	${DISTNAME:S/l/L/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
# compression
DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
