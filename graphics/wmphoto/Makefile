# $NetBSD: Makefile,v 1.15 2006/02/05 23:09:40 joerg Exp $
#

DISTNAME=	wmphoto-0.3a
PKGREVISION=	1
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
