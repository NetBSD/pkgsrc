# $NetBSD: Makefile,v 1.9 2010/11/15 22:57:09 abs Exp $
#

DISTNAME=	clutter-box2d-0.10.0
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/clutter-box2d/0.10/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Clutter Box2D integration library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	clutter-box2d.pc.in

.include "../../graphics/clutter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
