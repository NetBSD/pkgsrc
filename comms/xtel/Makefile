# $NetBSD: Makefile,v 1.10 2006/02/05 23:08:28 joerg Exp $
#

DISTNAME=	xtel-3.3.0
PKGREVISION=	3
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
