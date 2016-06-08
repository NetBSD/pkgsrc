# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:35 wiz Exp $

DISTNAME=	intervals-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/intervals/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/intervals
COMMENT=	Tools for handling intervals (ranges of comparable objects)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-infinity>=0.1.3:../../math/py-infinity

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
