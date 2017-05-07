# $NetBSD: Makefile,v 1.134 2017/05/07 21:32:30 he Exp $

DISTNAME=	tiff-4.0.7
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	ftp://download.osgeo.org/libtiff/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simplesystems.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files
LICENSE=	mit

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/tiff
CONFIGURE_ARGS+=	--without-x # just in case detects gl to build tiffgt

PKGCONFIG_OVERRIDE=	libtiff-4.pc.in

TEST_TARGET=		check

post-install:
	cd ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man3 && for file in *.3tiff; do\
		target=`${ECHO} $$file | sed "s/3tiff/3/"`; \
		${MV} $$file $$target; \
	done

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
# XXX for liblzma; there are more potential suppliers
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
