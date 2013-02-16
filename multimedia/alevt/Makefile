# $NetBSD: Makefile,v 1.21 2013/02/16 11:23:30 wiz Exp $

DISTNAME=	alevt-1.6.1
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.goron.de/~froese/alevt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.goron.de/~froese/
COMMENT=	Teletext decoder and browser for Brooktree 848 compatible TV cards

DEPENDS+=	fxtv>=1.02:../../multimedia/fxtv

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[56]*-* \
			NetBSD-[2-9]*-* DragonFly-*-*

USE_X11BASE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/pixmaps

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
