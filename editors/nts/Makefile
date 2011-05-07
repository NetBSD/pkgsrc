# $NetBSD: Makefile,v 1.1.1.1 2011/05/07 20:02:22 ryoon Exp $
#

DISTNAME=	nts-77
CATEGORIES=	editors
MASTER_SITES=	http://www.duke.edu/~dgraham/NTS/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.duke.edu/~dgraham/NTS/
COMMENT=	Simple GUI note taking application
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-wxWidgets>=2.8.7:../../x11/py-wxWidgets
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
