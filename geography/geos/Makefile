# $NetBSD: Makefile,v 1.16 2012/06/01 14:32:54 gdt Exp $

DISTNAME=	geos-3.3.4
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://geos.refractions.net/
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
