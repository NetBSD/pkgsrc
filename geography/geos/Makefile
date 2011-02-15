# $NetBSD: Makefile,v 1.13 2011/02/15 09:19:29 adam Exp $

DISTNAME=	geos-3.2.2
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://geos.refractions.net/
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
