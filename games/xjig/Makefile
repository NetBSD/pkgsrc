# $NetBSD: Makefile,v 1.4 1998/05/17 13:21:20 frueauf Exp $
#

DISTNAME=		xjig-2.4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/multiplayer
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org

USE_IMAKE=		yes
ALL_TARGET=		xjig xjig.0

CAT1=			xjig.0

post-install:
	${INSTALL_DATA_DIR} ${X11BASE}/lib/xjig
	${INSTALL_DATA} ${WRKSRC}/tina.gif ${X11BASE}/lib/xjig

.include "../../mk/bsd.pkg.mk"
