# $NetBSD: Makefile,v 1.7 2004/05/03 23:18:21 minskim Exp $
#

DISTNAME=	Mixer.app-1.8.0
PKGNAME=	mixer.app-1.8.0
CATEGORIES=	audio
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.fukt.bth.se/~per/mixer/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.fukt.bth.se/~per/mixer/
COMMENT=	Another mixer intended for the windowmaker dockapp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_LANGUAGES=	c++
USE_X11=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Mixer.app
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/Mixer.app

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
