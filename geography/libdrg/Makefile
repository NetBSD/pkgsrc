# $NetBSD: Makefile,v 1.11 2025/04/24 14:14:08 wiz Exp $
#

DISTNAME=	libdrg-0.0.81
PKGREVISION=	7
CATEGORIES=	geography
MASTER_SITES=	http://www.lexort.com/software/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.lexort.com/software/
COMMENT=	Library for reading and merging DRG files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdrg.pc.in

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
