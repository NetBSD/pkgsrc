# $NetBSD: Makefile,v 1.9 2009/03/18 19:41:45 gdt Exp $
#

DISTNAME=		geos-3.1.0
CATEGORIES=		geography
MASTER_SITES=		http://download.osgeo.org/geos/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://geos.refractions.net/
COMMENT=		C++ port of the Java Topology Suite (JTS)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
