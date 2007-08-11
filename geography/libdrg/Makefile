# $NetBSD: Makefile,v 1.1.1.1 2007/08/11 02:53:02 gdt Exp $
#

DISTNAME=	libdrg-0.0.81
CATEGORIES=	geography
MASTER_SITES=	http://www.lexort.com/software/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.lexort.com/software/
COMMENT=	Library for reading and merging DRG files.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdrg.pc.in

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
