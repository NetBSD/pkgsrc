# $NetBSD: Makefile,v 1.3 2018/10/15 08:59:11 adam Exp $

DISTNAME=	Logbook-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://logbook.readthedocs.io/
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
