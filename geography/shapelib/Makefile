# $NetBSD: Makefile,v 1.11 2024/08/14 11:30:45 gdt Exp $

VERSION=		1.6.1
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

# Earlier, we installed only some things, perhaps because there were a
# lot of binaries with non-namespaced names.  Now, we patch out
# contrib, and the set of installed binaries seems reasonable.
# \todo Perhaps revisit this, if upstream addreses
#   https://github.com/OSGeo/shapelib/issues/151
#INSTALL_TARGET=		install-libLTLIBRARIES install-libshp_la_includeHEADERS install-pkgconfigDATA

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
