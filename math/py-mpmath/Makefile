# $NetBSD: Makefile,v 1.20 2023/03/14 14:12:49 adam Exp $

DISTNAME=	mpmath-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpmath/}
MASTER_SITES+=	https://mpmath.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mpmath.org/
COMMENT=	Python library for arbitrary-precision FP arithmetic
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
# py-gmpy provides faster backend
DEPENDS+=	${PYPKGPREFIX}-gmpy2>=2.1.0:../../math/py-gmpy2
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.6:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} mpmath/tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
