# $NetBSD: Makefile,v 1.3 2019/08/22 09:57:08 nia Exp $

DISTNAME=	glw-8.0.0
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/glw/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/mesa/glw/
COMMENT=	GL widget for Athena and Motif
#LICENSE=	https://cgit.freedesktop.org/mesa/glw/tree/README

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	glw.pc.in

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
