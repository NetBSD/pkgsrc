# $NetBSD: Makefile,v 1.7 2006/07/02 10:12:25 rillig Exp $
#

DISTNAME=	plnode141
PKGNAME=	ploticus-examples-1.41
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.sgpr.net/download/ \
		http://gd.tuwien.ac.at/visual/ploticus/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.sgpr.net/
COMMENT=	Examples for the ploticus data plotting suite

NO_CONFIGURE=	YES
NO_BUILD=	YES

DIST_SUBDIR=	${PKGNAME_NOREV:S/-examples//}
EXDIR=		${PREFIX}/share/examples/ploticus

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${EXDIR}
	cd ${WRKSRC} && ${PAX} -rw -pp doc gallery tabgallery thumbnails thumbpng ${EXDIR}

.include "../../mk/bsd.pkg.mk"
