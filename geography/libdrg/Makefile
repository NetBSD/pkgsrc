# $NetBSD: Makefile,v 1.2 2007/08/16 22:31:11 joerg Exp $
#

DISTNAME=	libdrg-0.0.81
CATEGORIES=	geography
MASTER_SITES=	http://www.lexort.com/software/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.lexort.com/software/
COMMENT=	Library for reading and merging DRG files.

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libdrg.pc.in

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
