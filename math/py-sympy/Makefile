# $NetBSD: Makefile,v 1.12 2012/09/11 23:04:32 asau Exp $
#

DISTNAME=	sympy-0.7.1
PKGNAME=	${PYPKGPREFIX}-sympy-0.7.1
CATEGORIES=	math
MASTER_SITES=	http://sympy.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sympy/
COMMENT=	Python library for symbolic mathematics
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${CP} ${WRKSRC}/bin/isympy ${WRKSRC}/bin/isympy${PYVERSSUFFIX}
	${CP} ${WRKSRC}/doc/man/isympy.1 \
		${WRKSRC}/doc/man/isympy${PYVERSSUFFIX}.1

# advanced.pidigits is broken, don't worry if it fails
do-test:
	(cd ${WRKSRC}/examples && ${PYTHONBIN} all.py)

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
