# $NetBSD: Makefile,v 1.5 2003/11/30 22:58:41 jschauma Exp $

DISTNAME=	bzflag-1.7e6
PKGNAME=	${DISTNAME:S/e/.5./}
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=bzflag/}
EXTRACT_SUFX=   .tgz

MAINTAINER=	blymn@baea.com.au
HOMEPAGE=	http://www.bzflag.org/
COMMENT=	OpenGL tank game

USE_X11BASE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes
MAKE_ENV+=	X11BASE=${X11BASE} INSTALL_PREFIX=${X11PREFIX}

ALL_TARGET=	netbsd default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bzflag ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bzfls ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bzfrelay ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bzfs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/bzflag.6s ${PREFIX}/man/man6/bzflag.6
	${INSTALL_MAN} ${WRKSRC}/man/bzfls.6s ${PREFIX}/man/man6/bzfls.6
	${INSTALL_MAN} ${WRKSRC}/man/bzfrelay.6s ${PREFIX}/man/man6/bzfrelay.6
	${INSTALL_MAN} ${WRKSRC}/man/bzfs.6s ${PREFIX}/man/man6/bzfs.6
	${INSTALL_DATA_DIR} ${PREFIX}/share/bzflag
	${CP} ${WRKSRC}/data/* ${PREFIX}/share/bzflag

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
