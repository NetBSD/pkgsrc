# $NetBSD: Makefile,v 1.7 2014/01/25 10:30:13 wiz Exp $

DISTNAME=	mpmath-0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://mpmath.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mpmath/
COMMENT=	Python library for arbitrary-precision FP arithmetic
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	33

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	${RUN} cd ${WRKSRC}/build/lib/mpmath/tests; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/extension.mk"
# optional speedup
#.include "../../math/py-gmpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
