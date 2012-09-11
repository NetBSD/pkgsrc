# $NetBSD: Makefile,v 1.6 2012/09/11 23:04:31 asau Exp $
#

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

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	${RUN} cd ${WRKSRC}/build/lib/mpmath/tests; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/extension.mk"
# optional speedup
#.include "../../math/py-gmpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
