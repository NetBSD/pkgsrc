# $NetBSD: Makefile,v 1.4 2004/03/22 03:31:25 kristerw Exp $

DISTNAME=	alevt-1.6.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/video/}

MAINTAINER=	magick@bundy.zhadum.de
HOMEPAGE=	http://user.exit.de/froese/
COMMENT=	Teletext decoder and browser for Brooktree 848 compatible TV cards

DEPENDS+=	png>=1.2.1:../../graphics/png
DEPENDS+=	fxtv>=1.02:../../multimedia/fxtv
DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-* \
			NetBSD-[2-9]*-*

USE_X11BASE=	YES
USE_GNU_TOOLS+=	make

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
