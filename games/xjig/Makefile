# $NetBSD: Makefile,v 1.12 2003/07/17 21:39:37 grant Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		jigsaw puzzle

USE_IMAKE=		yes
ALL_TARGET=		xjig xjig.0

post-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${X11PREFIX}/lib/xjig

.include "../../mk/bsd.pkg.mk"
