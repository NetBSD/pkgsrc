# $NetBSD: Makefile,v 1.6 2019/08/21 08:58:23 adam Exp $

DISTNAME=	Logbook-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://logbook.readthedocs.io/
COMMENT=	Logging replacement for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-brotlipy-[0-9]*:../../archivers/py-brotlipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

pre-build:
	cd ${WRKSRC} && cython-${PYVERSSUFFIX} logbook/_speedups.pyx

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
