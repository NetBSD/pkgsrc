# $NetBSD: Makefile,v 1.11 2006/02/16 18:11:03 wiz Exp $
#

DISTNAME=	xtel-3.3.0
PKGREVISION=	4
CATEGORIES=	comms x11
MASTER_SITES=	http://pficheux.free.fr/xtel/download/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://pficheux.free.fr/xtel/
COMMENT=	Minitel(r) emulator

USE_IMAKE=	YES
USE_TOOLS+=	mkfontdir

FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/xtel
REQD_DIRS=	${PREFIX}/lib/X11/fonts/xtel

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
