# $NetBSD: Makefile,v 1.1 2014/07/05 19:28:06 rodent Exp $

DISTNAME=	orderedmultidict-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/o/orderedmultidict/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pypi.python.org/packages/source/o/orderedmultidict/
COMMENT=	Ordered Multivalue Dictionary - omdict
LICENSE=	unlicense

USE_LANGUAGES=	# none

post-install:
	# XXX: No access to ${EGG_INFODIR} ? Will be fixed in next version.
	${CHMOD} -x,go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
