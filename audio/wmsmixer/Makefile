# $NetBSD: Makefile,v 1.4 2003/07/02 13:15:34 agc Exp $
#

DISTNAME=	wmsmixer-0.5.1
CATEGORIES=	audio
MASTER_SITES=	http://www.hibernaculum.net/download/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.hibernaculum.net/wmsmixer.html
COMMENT=	Another mixer designed for WindowMaker (dockapp)

USE_BUILDLINK2=	YES
USE_IMAKE=	YES
NO_INSTALL_MANPAGES= YES

pre-build:
	${TOUCH} ${WRKSRC}/wmsmixer.man

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmsmixer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/wmsmixer
	${INSTALL_DATA} ${WRKSRC}/home.wmsmixer ${PREFIX}/share/examples/wmsmixer
	${INSTALL_DATA} ${WRKSRC}/README.wmmixer ${PREFIX}/share/doc/wmsmixer/README.wmsmixer

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
