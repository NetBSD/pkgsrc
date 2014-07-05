# $NetBSD: Makefile,v 1.1 2014/07/05 19:33:17 rodent Exp $

DISTNAME=	intervals-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/i/intervals/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/intervals
COMMENT=	Tools for handling intervals (ranges of comparable objects)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-infinity>=0.1.3:../../math/py-infinity

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
