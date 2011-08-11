# $NetBSD: Makefile,v 1.2 2011/08/11 12:46:29 obache Exp $
#

DISTNAME=	nwdiag-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/n/nwdiag/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://blockdiag.com/nwdiag/build/html/
COMMENT=	Simple network-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.7nb3:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=0.3.4:../../devel/py-funcparserlib
DEPENDS+=	${PYPKGPREFIX}-blockdiag>=0.8.7:../../graphics/py-blockdiag

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
