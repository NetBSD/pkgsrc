# $NetBSD: Makefile,v 1.15 2004/12/03 15:14:58 wiz Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Jigsaw puzzle

USE_IMAKE=		yes
BUILD_TARGET=		xjig xjig.0

USE_LANGUAGES=		c c++

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${X11PREFIX}/lib/xjig

.include "../../mk/bsd.pkg.mk"
