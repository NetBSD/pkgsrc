# $NetBSD: Makefile,v 1.11 2006/12/27 13:37:37 joerg Exp $

DISTNAME=	xjewel-1.6
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:S/contrib/R5contrib/}
EXTRACT_SUFX=	.tar.z

MAINTAINER=	jdc@NetBSD.org
COMMENT=	X windows-based dropping jewels game

USE_IMAKE=	yes
USE_TOOLS+=	gzcat bdftopcf mkfontdir

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
