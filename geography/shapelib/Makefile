# $NetBSD: Makefile,v 1.13 2026/03/25 23:34:15 gdt Exp $

VERSION=		1.6.3
#VERSION_RC=		rc2
DISTNAME=		shapelib-${VERSION}${VERSION_RC}
CATEGORIES=		geography
MASTER_SITES=		https://download.osgeo.org/shapelib/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://shapelib.maptools.org/
COMMENT=		Library for reading, writing and updating (limited) ESRI Shapefiles
LICENSE=		gnu-lgpl-v2 OR mit

WRKSRC=			${WRKDIR}/shapelib-${VERSION}

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
# Upstream does not document that gmake is required, but building with
# BSD make tries to build things that need shplib.la before it is built.
USE_TOOLS+=		gmake

# We patch out contrib.   Resolve this with upstream:
#   https://github.com/OSGeo/shapelib/issues/151

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
