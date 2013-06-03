# $NetBSD: Makefile,v 1.20 2013/06/03 10:05:08 wiz Exp $
#

DISTNAME=	clutter-cairo-0.8.2
PKGREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-cairo/0.8/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Clutter Cairo integrarion library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	clutter-cairo.pc.in

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.4
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/clutter08/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
