# $NetBSD: Makefile,v 1.1 2015/10/14 21:35:28 wiz Exp $

DISTNAME=	glw-8.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/glw/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/mesa/glw/
COMMENT=	GL widget for Athena and Motif
#LICENSE=	http://cgit.freedesktop.org/mesa/glw/tree/README

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	glw.pc.in

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
