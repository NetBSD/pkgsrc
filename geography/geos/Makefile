# $NetBSD: Makefile,v 1.17 2012/06/03 16:05:44 gdt Exp $

DISTNAME=	geos-3.3.4
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/
EXTRACT_SUFX=	.tar.bz2

# NOTE: geos uses -release for versioning lib/libgeos.la, and seems to
# change the shlib name (not just the version, but the *name*) on
# every release.  If this continues, a recursive revbump is required
# on every update.

# This has been reported as a bug to the upstream mailinglist:
# http://lists.osgeo.org/pipermail/geos-devel/2012-June/005860.html

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
