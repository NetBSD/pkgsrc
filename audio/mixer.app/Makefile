# $NetBSD: Makefile,v 1.11 2006/02/05 23:08:12 joerg Exp $
#

DISTNAME=	Mixer.app-1.8.0
PKGNAME=	mixer.app-1.8.0
PKGREVISION=	1
CATEGORIES=	audio
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.fukt.bth.se/~per/mixer/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.fukt.bth.se/~per/mixer/
COMMENT=	Another mixer intended for the windowmaker dockapp

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Mixer.app
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/Mixer.app

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
