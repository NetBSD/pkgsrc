# $NetBSD: Makefile,v 1.14 2005/12/05 20:50:23 rillig Exp $
#

DISTNAME=	wmphoto-0.3a
CATEGORIES=	graphics
MASTER_SITES=	http://www.dcc.uchile.cl/~amartoq/wmphoto/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.dcc.uchile.cl/~amartoq/wmphoto/
COMMENT=	Dock-app that can show you a photo

BUILD_DIRS=	wmphoto
USE_X11BASE=	YES
USE_TOOLS+=	gmake
MAKE_ENV+=	X11PREFIX=${X11PREFIX:Q} X11BASE=${X11BASE:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/HINTS ${PREFIX}/share/doc/wmphoto

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
