# $NetBSD: Makefile,v 1.6 2012/11/19 20:00:06 cheusov Exp $
#

DISTNAME=	nwdiag-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/n/nwdiag/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://blockdiag.com/nwdiag/build/html/
COMMENT=	Simple network-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-blockdiag>=1.1.2:../../graphics/py-blockdiag

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
