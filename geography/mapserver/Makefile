# $NetBSD: Makefile,v 1.2 2004/01/03 18:49:41 reed Exp $
#

DISTNAME=		mapserver-4.0
PKGREVISION=		1
CATEGORIES=		geography www
MASTER_SITES=		http://cvs.gis.umn.edu/dist/

MAINTAINER=		hdp@cs.msu.edu
HOMEPAGE=		http://mapserver.gis.umn.edu/dist/
COMMENT=		Environment for building spatially enabled Internet apps

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-gd=${PREFIX}				\
			--with-libiconv=${PREFIX}			\
			--with-zlib=${BUILDLINK_PREFIX.zlib}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmap.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/map.h ${PREFIX}/include
.for PROGRAM in shp2img shp2pdf mapserv legend shptree shptreevis 	\
	shptreetst scalebar sortshp
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
