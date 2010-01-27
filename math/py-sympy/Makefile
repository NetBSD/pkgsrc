# $NetBSD: Makefile,v 1.7 2010/01/27 14:21:19 drochner Exp $
#

DISTNAME=	sympy-0.6.6
PKGNAME=	${PYPKGPREFIX}-sympy-0.6.6
CATEGORIES=	math
MASTER_SITES=	http://sympy.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sympy/
COMMENT=	Python library for symbolic mathematics

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	25 24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${CP} ${WRKSRC}/bin/isympy ${WRKSRC}/bin/isympy${PYVERSSUFFIX}
	${CP} ${WRKSRC}/doc/man/isympy.1 \
		${WRKSRC}/doc/man/isympy${PYVERSSUFFIX}.1

do-test:
	(cd ${WRKSRC}/examples && ${PYTHONBIN} all.py)

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
