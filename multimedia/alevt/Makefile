# $NetBSD: Makefile,v 1.8 2005/03/29 16:10:22 magick Exp $

DISTNAME=	alevt-1.6.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/video/}

MAINTAINER=	magick@bundy.zhadum.de
HOMEPAGE=	http://user.exit.de/froese/
COMMENT=	Teletext decoder and browser for Brooktree 848 compatible TV cards

DEPENDS+=	fxtv>=1.02:../../multimedia/fxtv

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[56]*-* \
			NetBSD-[2-9]*-*

USE_DIRS+=	xdg-1.1
USE_X11BASE=	YES
USE_GNU_TOOLS+=	make

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
