# $NetBSD: Makefile,v 1.16 2012/10/02 17:11:08 tron Exp $
#

DISTNAME=	clutter-cairo-0.8.2
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-cairo/0.8/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Clutter Cairo integrarion library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	clutter-cairo.pc.in

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.4
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/clutter08/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
