# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:39:26 jlam Exp $
#

DISTNAME=	wmsmixer-0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.hibernaculum.net/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.hibernaculum.net/wmsmixer.html
COMMENT=	Another mixer designed for WindowMaker (dockapp)

USE_IMAKE=	YES
NO_INSTALL_MANPAGES= YES

pre-build:
	${TOUCH} ${WRKSRC}/wmsmixer.man

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmsmixer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/wmsmixer
	${INSTALL_DATA} ${WRKSRC}/home.wmsmixer ${PREFIX}/share/examples/wmsmixer
	${INSTALL_DATA} ${WRKSRC}/README.wmmixer ${PREFIX}/share/doc/wmsmixer/README.wmsmixer

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
