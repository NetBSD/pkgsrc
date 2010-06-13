# $NetBSD: Makefile,v 1.6 2010/06/13 22:44:27 wiz Exp $
#

DISTNAME=	clutter-box2d-0.10.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.clutter-project.org/sources/clutter-box2d/0.10/

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
