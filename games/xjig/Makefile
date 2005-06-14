# $NetBSD: Makefile,v 1.16 2005/06/14 18:07:47 jmmv Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Jigsaw puzzle

USE_IMAKE=		yes
USE_LANGUAGES=		c c++

BUILD_TARGET=		xjig all

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${X11PREFIX}/lib/xjig

.include "../../mk/bsd.pkg.mk"
