# $NetBSD: Makefile,v 1.158.2.1 2023/08/18 18:13:39 bsiegert Exp $

VERSION_BASE=	4.5.1
# Accomodate testing unreleased versions.
#VERSION_RC=	rc3
DISTNAME=	tiff-${VERSION_BASE}${VERSION_RC}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://download.osgeo.org/libtiff/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://simplesystems.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files
LICENSE=	mit

WRKSRC=		${WRKDIR}/tiff-${VERSION_BASE}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_LANGUAGES=		c99 c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/tiff
CONFIGURE_ARGS+=	--without-x # just in case detects gl to build tiffgt
CONFIGURE_ARGS+=	--disable-sphinx
CONFIGURE_ARGS+=	--disable-webp
CONFIGURE_ARGS+=	--disable-zstd

PKGCONFIG_OVERRIDE=	libtiff-4.pc.in

TEST_TARGET=		check

post-extract:
	cd ${WRKSRC} && \
	${MV} -f VERSION VERSION.txt

post-install:
	cd ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man3 && for file in *.3tiff; do\
		target=`${ECHO} $$file | sed "s/3tiff/3/"`; \
		${MV} $$file $$target; \
	done
	cd ${DESTDIR}/${PREFIX}/share/doc/${PKGBASE} && \
	${MV} -f VERSION.txt VERSION

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
# XXX for liblzma; there are more potential suppliers
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/jbigkit/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
