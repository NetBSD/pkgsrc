# $NetBSD: Makefile,v 1.17 2006/12/15 20:32:57 joerg Exp $
#

DISTNAME=	wmphoto-0.3a
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dcc.uchile.cl/~amartoq/wmphoto/

MAINTAINER=	pkgsrc-users@NetBSD.org
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

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
