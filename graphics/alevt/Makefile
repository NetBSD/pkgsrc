# $NetBSD: Makefile,v 1.6 2001/05/22 09:32:19 wiz Exp $

DISTNAME=	alevt-1.6.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/video/}

MAINTAINER=	magick@bundy.zhadum.de
HOMEPAGE=	http://user.exit.de/froese/
COMMENT=	Teletext decoder and browser for Brooktree 848 compatible TV cards

DEPENDS+=	png>=1.0.11:../../graphics/png
DEPENDS+=	fxtv>=1.02:../../graphics/fxtv

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

USE_X11BASE=	YES
USE_GMAKE=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
