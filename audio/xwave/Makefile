# $NetBSD: Makefile,v 1.14 2004/04/09 00:57:47 minskim Exp $
#

DISTNAME=		xwave2
PKGNAME=		xwave-2.0
CATEGORIES=		audio x11
MASTER_SITES=		# empty

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Audio player/recorder/editor for the X Window System

USE_BUILDLINK3=		YES
USE_IMAKE=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xwave ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/XWave ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xwave2
	${INSTALL_DATA} ${WRKSRC}/README \
			${WRKSRC}/README-XWAVE2 \
			${WRKSRC}/README.v06 \
			${WRKSRC}/COPYING \
			${WRKSRC}/INSTALL \
			${PREFIX}/share/doc/xwave2

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
