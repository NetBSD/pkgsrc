# $NetBSD: Makefile,v 1.6 2026/11/25 14:42:13 wiz Exp $

DISTNAME=	glw-8.0.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/glw/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/mesa/glw/
COMMENT=	GL widget for Athena and Motif
LICENSE=	sgi-free-software-b-v2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

PKGCONFIG_OVERRIDE+=	glw.pc.in

.include "../../mk/mesa.buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
