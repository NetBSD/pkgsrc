# $NetBSD: Makefile,v 1.7 2000/07/11 08:43:54 agc Exp $
#

DISTNAME=		xjig-2.4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/multiplayer/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org

USE_IMAKE=		yes
ALL_TARGET=		xjig xjig.0

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${X11PREFIX}/lib/xjig

.include "../../mk/bsd.pkg.mk"
