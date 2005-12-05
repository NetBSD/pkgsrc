# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:22 rillig Exp $
#

DISTNAME=	plnode141
PKGNAME=	ploticus-examples-1.41
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
.for dir in doc gallery tabgallery thumbnails thumbpng
	${INSTALL_DATA_DIR} ${EXDIR}/${dir}
	${CP} -R ${WRKSRC}/${dir} ${EXDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
