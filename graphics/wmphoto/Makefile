# $NetBSD: Makefile,v 1.5 2003/06/18 09:22:19 agc Exp $
#

DISTNAME=	wmphoto-0.3a
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/wmphoto
CATEGORIES=	graphics
MASTER_SITES=	http://www.dcc.uchile.cl/~amartoq/wmphoto/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.dcc.uchile.cl/~amartoq/wmphoto/
COMMENT=	dock-app that can show you a photo

USE_X11BASE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
MAKE_ENV+=	X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/wmphoto
	${INSTALL_DATA} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wmphoto

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
