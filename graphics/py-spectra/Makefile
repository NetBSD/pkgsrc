# $NetBSD: Makefile,v 1.4 2024/05/17 13:21:34 jperkin Exp $

DISTNAME=	spectra-0.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spectra/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/jsvine/spectra
COMMENT=	Color scales and color conversion made easy for Python
LICENSE=	mit

DEPENDS=	${PYPKGPREFIX}-colormath>=3.0.0:../../math/py-colormath
TEST_DEPENDS=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m nose -v test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
