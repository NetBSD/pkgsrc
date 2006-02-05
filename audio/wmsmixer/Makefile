# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:15 joerg Exp $
#

DISTNAME=	wmsmixer-0.5.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.hibernaculum.net/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.hibernaculum.net/wmsmixer.html
COMMENT=	Another mixer designed for WindowMaker (dockapp)

NOT_FOR_PLATFORM=	Interix-*-*

USE_IMAKE=	YES
USE_LANGUAGES=	c++
NO_INSTALL_MANPAGES= YES

pre-build:
	${TOUCH} ${WRKSRC}/wmsmixer.man

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmsmixer
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/wmsmixer
	${INSTALL_DATA} ${WRKSRC}/home.wmsmixer \
		${PREFIX}/share/examples/wmsmixer
	${INSTALL_DATA} ${WRKSRC}/README.wmmixer \
		${PREFIX}/share/doc/wmsmixer/README.wmsmixer

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
