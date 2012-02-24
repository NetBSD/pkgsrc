# $NetBSD: Makefile,v 1.10 2012/02/24 19:43:03 drochner Exp $
#

DISTNAME=	sympy-0.7.1
PKGNAME=	${PYPKGPREFIX}-sympy-0.7.1
CATEGORIES=	math
MASTER_SITES=	http://sympy.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sympy/
COMMENT=	Python library for symbolic mathematics
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	27 26 25
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
