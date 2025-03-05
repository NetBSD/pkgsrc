# $NetBSD: Makefile,v 1.15 2025/03/05 09:51:21 wiz Exp $

DISTNAME=	logbook-1.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://logbook.readthedocs.io/
COMMENT=	Logging replacement for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
# compression
DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
