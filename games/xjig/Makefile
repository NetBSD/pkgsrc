# $NetBSD: Makefile,v 1.20 2006/12/27 13:37:37 joerg Exp $
#

DISTNAME=		xjig-2.4
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Jigsaw puzzle

USE_IMAKE=		yes
USE_LANGUAGES=		c c++

BUILD_TARGET=		xjig all

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${PREFIX}/lib/xjig

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
