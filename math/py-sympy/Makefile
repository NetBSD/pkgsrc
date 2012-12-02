# $NetBSD: Makefile,v 1.13 2012/12/02 12:33:23 wen Exp $
#

DISTNAME=	sympy-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://sympy.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sympy/
COMMENT=	Python library for symbolic mathematics
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fixing python path
SUBST_FILES.python+=    sympy/galgebra/GA.py
SUBST_FILES.python+=	sympy/galgebra/tests/test_GA.py
SUBST_SED.python=	-e "s,/usr/bin/python,${PYTHONBIN},"

SUBST_CLASSES+=		python2
SUBST_STAGE.python2=	post-patch
SUBST_MESSAGE.python2=	Fixing python path
SUBST_FILES.python2+=	sympy/mpmath/tests/runtests.py
SUBST_SED.python2=	-e "s,/usr/bin/env python,${PYTHONBIN},"

post-extract:
	${CP} ${WRKSRC}/bin/isympy ${WRKSRC}/bin/isympy${PYVERSSUFFIX}
	${CP} ${WRKSRC}/doc/man/isympy.1 \
		${WRKSRC}/doc/man/isympy${PYVERSSUFFIX}.1

# advanced.pidigits is broken, don't worry if it fails
do-test:
	(cd ${WRKSRC}/examples && ${PYTHONBIN} all.py)

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
