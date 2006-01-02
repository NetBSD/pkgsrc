# $NetBSD: Makefile,v 1.9 2006/01/02 16:17:09 joerg Exp $
#

DISTNAME=	xtel-3.3.0
PKGREVISION=	2
CATEGORIES=	comms x11
MASTER_SITES=	http://pficheux.free.fr/xtel/download/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://pficheux.free.fr/xtel/
COMMENT=	Minitel(r) emulator

USE_IMAKE=	YES
USE_TOOLS+=	mkfontdir

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
