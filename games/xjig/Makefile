# $NetBSD: Makefile,v 1.18 2006/02/05 23:09:24 joerg Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Jigsaw puzzle

USE_IMAKE=		yes
USE_LANGUAGES=		c c++

BUILD_TARGET=		xjig all

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${PREFIX}/lib/xjig

.include "../../mk/bsd.pkg.mk"
