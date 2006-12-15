# $NetBSD: Makefile,v 1.13 2006/12/15 20:32:53 joerg Exp $
#

DISTNAME=	xtel-3.3.0
PKGREVISION=	5
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
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
