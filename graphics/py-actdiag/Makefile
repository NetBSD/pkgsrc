# $NetBSD: Makefile,v 1.1.1.1 2011/08/07 15:43:50 obache Exp $
#

DISTNAME=	actdiag-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://pypi.python.org/packages/source/a/actdiag/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://blockdiag.com/actdiag/build/html/
COMMENT=	Simple activity-diagram image generator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-imaging>=1.1.7nb3:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=0.3.4:../../devel/py-funcparserlib
DEPENDS+=	${PYPKGPREFIX}-blockdiag>=0.8.1:../../graphics/py-blockdiag

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
