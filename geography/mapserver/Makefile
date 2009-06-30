# $NetBSD: Makefile,v 1.18 2009/06/30 00:07:16 joerg Exp $
#

DISTNAME=		mapserver-4.0
PKGREVISION=		5
CATEGORIES=		geography www
MASTER_SITES=		http://download.osgeo.org/mapserver/

MAINTAINER=		hdp@cs.msu.edu
HOMEPAGE=		http://mapserver.gis.umn.edu/
COMMENT=		Environment for building spatially enabled Internet apps

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-gd=${PREFIX:Q}				\
			--with-libiconv=${PREFIX:Q}			\
			--with-zlib=${BUILDLINK_PREFIX.zlib}

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmap.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/map.h ${DESTDIR}${PREFIX}/include
.for f in shp2img shp2pdf mapserv legend shptree shptreevis		\
	shptreetst scalebar sortshp
	${INSTALL_PROGRAM} ${WRKSRC}/${f:Q} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
