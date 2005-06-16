# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:56 jlam Exp $
#

DISTNAME=		mapserver-4.0
PKGREVISION=		3
CATEGORIES=		geography www
MASTER_SITES=		http://cvs.gis.umn.edu/dist/

MAINTAINER=		hdp@cs.msu.edu
HOMEPAGE=		http://mapserver.gis.umn.edu/
COMMENT=		Environment for building spatially enabled Internet apps

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-gd=${PREFIX}				\
			--with-libiconv=${PREFIX}			\
			--with-zlib=${BUILDLINK_PREFIX.zlib}

INSTALLATION_DIRS=	bin include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmap.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/map.h ${PREFIX}/include
.for PROGRAM in shp2img shp2pdf mapserv legend shptree shptreevis 	\
	shptreetst scalebar sortshp
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
