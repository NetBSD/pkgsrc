# $NetBSD: Makefile,v 1.2 2002/10/21 12:24:11 wiz Exp $
#

DISTNAME=	wmphoto-0.3a
CATEGORIES=	graphics
MASTER_SITES=	http://www.dcc.uchile.cl/~amartoq/wmphoto/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dcc.uchile.cl/~amartoq/wmphoto/
COMMENT=	dock-app that can show you a photo

USE_X11BASE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
WRKSRC=		${WRKDIR}/${PKGNAME}/wmphoto
MAKE_ENV+=	X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wmphoto

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
