# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 13:35:09 agc Exp $
#

DISTNAME=	wmphoto-0.3a
CATEGORIES=	graphics
MASTER_SITES=	http://www.dcc.uchile.cl/~amartoq/wmphoto/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dcc.uchile.cl/~amartoq/wmphoto/
COMMENT=	dock-app that can show you a photo

USE_X11BASE=	YES
USE_XPM=	YES
USE_GMAKE=	YES
WRKSRC=		${WRKDIR}/${PKGNAME}/wmphoto
MAKE_ENV+=	X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wmphoto

.include "../../mk/bsd.pkg.mk"
