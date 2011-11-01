# $NetBSD: Makefile,v 1.9 2011/11/01 06:01:41 sbd Exp $

DISTNAME=	OpenSceneGraph-${OSGVER}
PKGNAME=	osg-${OSGVER}
PKGREVISION=	6
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.openscenegraph.org/downloads/stable_releases/OpenSceneGraph-${OSGVER}/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openscenegraph.org/
COMMENT=	High performance 3D graphics toolkit

LICENSE=	gnu-lgpl-v2.1

OSGVER=		2.8.3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	packaging/pkgconfig/openscenegraph.pc.in
PKGCONFIG_OVERRIDE+=	packaging/pkgconfig/openthreads.pc.in

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
