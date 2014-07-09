# $NetBSD: Makefile,v 1.3 2014/07/09 00:09:30 obache Exp $

DISTNAME=	orderedmultidict-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/o/orderedmultidict/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/gruns/orderedmultidict
COMMENT=	Ordered Multivalue Dictionary - omdict
LICENSE=	unlicense

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.if ${PYPKGPREFIX} == "py26"
DEPENDS+=	${PYPKGPREFIX}-ordereddict-[0-9]*:../../devel/py-ordereddict
.endif
.include "../../mk/bsd.pkg.mk"
