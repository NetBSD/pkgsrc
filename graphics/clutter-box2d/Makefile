# $NetBSD: Makefile,v 1.1.1.1 2008/12/14 11:02:30 obache Exp $
#

DISTNAME=	clutter-box2d-0.8.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-box2d/0.8/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Clutter Box2D integration library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	clutter-box2d.pc.in

.include "../../graphics/clutter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
