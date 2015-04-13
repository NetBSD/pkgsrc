# $NetBSD: Makefile,v 1.7 2015/04/13 23:12:40 rodent Exp $

DISTNAME=	orderedmultidict-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/o/orderedmultidict/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/gruns/orderedmultidict
COMMENT=	Ordered Multivalue Dictionary - omdict
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
	chmod -x ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
