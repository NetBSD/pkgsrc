# $NetBSD: Makefile,v 1.2 2007/01/26 18:41:13 joerg Exp $

DISTNAME=	WMmp-0.10.0
CATEGORIES=	audio
MASTER_SITES= 	http://mercury.chem.pitt.edu/~shank/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://musicpd.org/WMmp.shtml
COMMENT=	Window Maker dock app for interfacing MPD

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
