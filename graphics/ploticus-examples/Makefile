# $NetBSD: Makefile,v 1.13 2013/06/30 15:17:18 ryoon Exp $
#

DISTNAME=	plnode200
PKGNAME=	ploticus-examples-2.00
CATEGORIES=	graphics
MASTER_SITES=	http://gd.tuwien.ac.at/visual/ploticus/download/

MAINTAINER=	rh@NetBSD.org
# HOMEPAGE=	http://www.sgpr.net/
# domain squatted
COMMENT=	Examples for the ploticus data plotting suite

USE_TOOLS+=	pax

NO_CONFIGURE=	YES
NO_BUILD=	YES

DIST_SUBDIR=	${PKGNAME_NOREV:S/-examples//}
EXDIR=		${PREFIX}/share/examples/ploticus

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXDIR}
	cd ${WRKSRC} && pax -rw -pp index.html doc gallery man tabgallery thumbnails thumbpng ${DESTDIR}${EXDIR}

.include "../../mk/bsd.pkg.mk"
