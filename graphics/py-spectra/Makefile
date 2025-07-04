# $NetBSD: Makefile,v 1.8 2025/07/04 09:08:35 wiz Exp $

DISTNAME=	spectra-0.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spectra/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/jsvine/spectra
COMMENT=	Color scales and color conversion made easy for Python
LICENSE=	mit

DEPENDS=	${PYPKGPREFIX}-colormath>=3.0.0:../../math/py-colormath
TEST_DEPENDS=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m nose -v test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
