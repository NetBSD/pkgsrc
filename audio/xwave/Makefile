# $NetBSD: Makefile,v 1.11 2001/12/02 21:24:35 wiz Exp $
#

DISTNAME=		xwave2
PKGNAME=		xwave-2.0
CATEGORIES=		audio x11
MASTER_SITES=		# empty

MAINTAINER=		hubertf@netbsd.org
COMMENT=		Audio player/recorder/editor for the X Window System

USE_IMAKE=		YES
USE_XPM=		YES

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

.include "../../mk/bsd.pkg.mk"
