# $NetBSD: Makefile,v 1.2 2002/09/21 00:46:08 jlam Exp $
#

DISTNAME=	Mixer.app-1.7.0
PKGNAME=	mixer.app-1.7.0
CATEGORIES=	audio
MASTER_SITES=	http://www.fukt.bth.se/~per/mixer/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.student.hk-r.se/~pt96pli/mixer/
COMMENT=	Another mixer intended for the windowmaker dockapp

USE_BUILDLINK2=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Mixer.app ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Mixer.app
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/Mixer.app

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
