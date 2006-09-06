# $NetBSD: Makefile,v 1.13 2006/09/06 15:38:32 tron Exp $

DISTNAME=	alevt-1.6.0
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/video/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://user.exit.de/froese/
COMMENT=	Teletext decoder and browser for Brooktree 848 compatible TV cards

DEPENDS+=	fxtv>=1.02:../../multimedia/fxtv

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[56]*-* \
			NetBSD-[2-9]*-*

USE_DIRS+=	xdg-1.1
USE_X11BASE=	YES
USE_TOOLS+=	gmake

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
