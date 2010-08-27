# $NetBSD: Makefile,v 1.1.1.1 2010/08/27 11:42:58 adam Exp $

DISTNAME=	qgis_1.5.0
PKGNAME=	qgis-1.5.0
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/qgis/src/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.qgis.org/
COMMENT=	Geographic Information System (GIS)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++ fortran
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
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
