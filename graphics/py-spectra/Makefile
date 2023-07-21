# $NetBSD: Makefile,v 1.2 2023/07/21 08:21:18 jperkin Exp $

DISTNAME=	spectra-0.0.11
PKGNAME=	${PYPKGPREFIX}-spectra-0.0.11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spectra/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/spectra
COMMENT=	Color scales and color conversion made easy for Python
LICENSE=	mit

DEPENDS=	${PYPKGPREFIX}-colormath>=3.0.0:../../math/py-colormath

TEST_DEPENDS=	${PYPKGPREFIX}-nose>0:../../devel/py-nose

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m nose -v test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
