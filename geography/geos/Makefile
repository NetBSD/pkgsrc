# $NetBSD: Makefile,v 1.20 2012/11/15 22:07:27 gdt Exp $

DISTNAME=	geos-3.3.6
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/
EXTRACT_SUFX=	.tar.bz2

# geos has two libraries:
#   geos_c (C), which follows normal versioning rules
#   geos (C++), which uses -release, and changes on every release

# According to the geos project, the C++ interface should not be
# directly used and other packages should not link against it.  This
# is currently underdocumented:
#   http://trac.osgeo.org/geos/ticket/553
#   http://lists.osgeo.org/pipermail/geos-devel/2012-June/005860.html

# Therefore, pkgsrc will perform a recursive revbump when the geos_c
# shlib version changes, and will generally ignore geos shlib name
# changes.  The following packages incorrectly (from the geos
# viewpoint) link directly against -lgeos and should be revbumped on
# every update (and fixed not to use -lgeos):
#   geography/gdal-lib

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://geos.refractions.net/
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
