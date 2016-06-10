# $NetBSD: Makefile,v 1.12 2016/06/10 09:06:41 wiz Exp $

DISTNAME=	mpmath-0.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mpmath/} \
		http://mpmath.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpmath.org/
COMMENT=	Python library for arbitrary-precision FP arithmetic
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_FILES.python+=	mpmath/matrices/eigen.py mpmath/matrices/eigen_symmetric.py
SUBST_FILES.python+=	mpmath/tests/test_eigen.py mpmath/tests/test_eigen_symmetric.py
SUBST_FILES.python+=	mpmath/tests/test_levin.py
SUBST_MESSAGE.python=	Fixing path to Python interpreter.
SUBST_SED.python=	-e "s,/usr/bin/python,${PYTHONBIN},g"

SUBST_CLASSES+=		python2
SUBST_STAGE.python2=	post-patch
SUBST_FILES.python2+=	mpmath/tests/runtests.py
SUBST_MESSAGE.python2=	Fixing path to Python interpreter.
SUBST_SED.python2=	-e "s,/usr/bin/env python,${PYTHONBIN},g"

do-test:
	${RUN} cd ${WRKSRC}/build/lib/mpmath/tests; \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} runtests.py

.include "../../lang/python/extension.mk"
# optional speedup
#.include "../../math/py-gmpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
