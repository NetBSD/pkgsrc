# $NetBSD: Makefile,v 1.12 2006/03/09 21:04:42 jlam Exp $
#

DISTNAME=	wmsmixer-0.5.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.hibernaculum.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
