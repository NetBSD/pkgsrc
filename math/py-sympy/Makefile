# $NetBSD: Makefile,v 1.2 2008/05/29 17:59:25 drochner Exp $
#

DISTNAME=	sympy-0.5.15
PKGNAME=	${PYPKGPREFIX}-sympy-0.5.15
CATEGORIES=	math
MASTER_SITES=	http://sympy.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sympy/
COMMENT=	Python library for symbolic mathematics

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${CP} ${WRKSRC}/bin/isympy ${WRKSRC}/bin/isympy${PYVERSSUFFIX}
	${CP} ${WRKSRC}/doc/man/isympy.1 \
		${WRKSRC}/doc/man/isympy${PYVERSSUFFIX}.1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
