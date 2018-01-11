# $NetBSD: Makefile,v 1.14 2018/01/11 08:07:44 adam Exp $

DISTNAME=	mpmath-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpmath/}
MASTER_SITES+=	http://mpmath.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpmath.org/
COMMENT=	Python library for arbitrary-precision FP arithmetic
LICENSE=	modified-bsd

# py-gmpy provides faster backend
DEPENDS+=	${PYPKGPREFIX}-gmpy-[0-9]*:../../math/py-gmpy

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/mpmath/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
