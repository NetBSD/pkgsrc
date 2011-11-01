# $NetBSD: Makefile,v 1.10 2011/11/01 06:01:24 sbd Exp $

DISTNAME=	qgis-1.6.0
PKGREVISION=	5
CATEGORIES=	geography
MASTER_SITES=	http://qgis.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.qgis.org/
COMMENT=	Geographic Information System (GIS)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bison perl
USE_X11=		yes

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qwt-qt4/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
