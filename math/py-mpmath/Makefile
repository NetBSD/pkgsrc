# $NetBSD: Makefile,v 1.5 2012/04/08 19:09:07 wiz Exp $
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
PKG_DESTDIR_SUPPORT= user-destdir

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	${RUN} cd ${WRKSRC}/build/lib/mpmath/tests; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/extension.mk"
# optional speedup
#.include "../../math/py-gmpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
