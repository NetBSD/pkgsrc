# $NetBSD: Makefile,v 1.10 2003/02/26 04:07:49 jschauma Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
COMMENT=		jigsaw puzzle

USE_IMAKE=		yes
ALL_TARGET=		xjig xjig.0

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${X11PREFIX}/lib/xjig

.include "../../mk/bsd.pkg.mk"
