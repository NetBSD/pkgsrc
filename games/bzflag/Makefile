# $NetBSD: Makefile,v 1.1.1.1 2002/09/24 12:49:10 blymn Exp $

DISTNAME=	bzflag-1.7e6
PKGNAME=	${DISTNAME:S/e/.5./}
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
	${INSTALL_DATA_DIR} ${PREFIX}/share/bzflag
	${CP} ${WRKSRC}/data/* ${PREFIX}/share/bzflag

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
