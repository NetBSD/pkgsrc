# $NetBSD: Makefile,v 1.5 2004/04/11 17:26:25 xtraeme Exp $
#

DISTNAME=	Mixer.app-1.8.0
PKGNAME=	mixer.app-1.8.0
CATEGORIES=	audio
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.fukt.bth.se/~per/mixer/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.fukt.bth.se/~per/mixer/
COMMENT=	Another mixer intended for the windowmaker dockapp

USE_BUILDLINK3=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Mixer.app
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/Mixer.app

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
