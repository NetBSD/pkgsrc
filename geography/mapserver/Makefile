# $NetBSD: Makefile,v 1.119 2024/08/22 15:34:00 gdt Exp $

DISTNAME=	mapserver-8.2.1
CATEGORIES=	geography www
MASTER_SITES=	http://download.osgeo.org/mapserver/

MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://mapserver.org/
COMMENT=	Environment for building spatially enabled Internet apps
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"
# cmake hides what it is doing; ask it to be like traditional builds.
MAKE_FLAGS+=		VERBOSE=1

# To find out what can be set in the cmake build.
# \todo Hoist to cmake/build.mk.
cmake-options:
	(cd ${WRKSRC}/cmake-pkgsrc-build && cmake -L ..) > OPTIONS

# \todo Check/explain/gc.
USE_PKGLOCALEDIR=	yes

# \todo File an upstream bug, and improve this (DOCDIR).
INSTALLATION_DIRS+=	share/examples/mapserver
post-install:
	mv ${DESTDIR}/${PREFIX}/etc/mapserver-sample.conf ${DESTDIR}/${PREFIX}/share/examples/mapserver/mapserver.conf
CONF_FILES+=		share/examples/mapserver/mapserver.conf ${PKG_SYSCONFDIR}/mapserver.conf

# Upstream does not document dependencies.  Instead they say to try to
# build and when you see an error guess at what to add until it
# builds.  (Really!)

.include "options.mk"

# \todo Adjust to current requirements.
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
