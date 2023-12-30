# $NetBSD: Makefile,v 1.10 2023/12/30 10:49:33 wiz Exp $

DISTNAME=		shapelib-1.6.0
CATEGORIES=		geography
MASTER_SITES=		https://download.osgeo.org/shapelib/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://shapelib.maptools.org/
COMMENT=		Library for reading, writing and updating (limited) ESRI Shapefiles
LICENSE=		gnu-lgpl-v2 OR mit

USE_LANGUAGES=		c99 c++

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

MAKE_JOBS_SAFE=		no

CHECK_PORTABILITY_SKIP+=	tests/test1.sh

# \todo Explain why we don't install what shapelib installs.
# \todo Perhaps file a bug upstream that the bin programs are not namespaced.
BUILD_TARGET=		libshp.la
INSTALL_TARGET=		install-libLTLIBRARIES install-libshp_la_includeHEADERS install-pkgconfigDATA

.include "../../mk/bsd.pkg.mk"
