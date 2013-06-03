# $NetBSD: Makefile,v 1.22 2013/06/03 10:05:08 wiz Exp $
#

DISTNAME=	clutter-box2d-0.10.0
PKGREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/clutter-box2d/0.10/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clutter-project.org/
COMMENT=	Clutter Box2D integration library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	clutter-box2d.pc.in

.include "../../graphics/clutter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
