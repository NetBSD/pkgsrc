# $NetBSD: Makefile,v 1.123 2024/09/21 10:24:28 wiz Exp $

DISTNAME=	mapserver-8.2.2
PKGREVISION=	1
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

# Mandatory dependencies (ordered by cmake configure status summary).
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
# We might need 2.13.2, which seems to have an API break relative to
# 2.13.0, but there's no NEWS that indicates that, so it is left to
# anyone using old freetype to address this.
.include "../../graphics/freetype2/buildlink3.mk"

# Optional dependencies.
# Lean to including optional features if they don't hurt much, as
# mapserver is hardly for low-resources systems.
.include "../../graphics/giflib/buildlink3.mk"
# mysql: option
.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
# svgcairo: no
# rsvg: no
# curl: no
# pixman: no
.include "../../textproc/libxml2/buildlink3.mk"
# postgis: option
.include "../../geography/geos/buildlink3.mk"
# fastcgi: option
.include "../../devel/protobuf-c/buildlink3.mk"
# oracle spatial: not in pkgsrc
# exempi xmp: no (?)

# Dependencies cmake looks for, not listed above
.include "../../devel/zlib/buildlink3.mk"
#  found and "enabled" but not clearly present in built objects
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
