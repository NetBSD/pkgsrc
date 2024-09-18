# $NetBSD: Makefile,v 1.166 2024/09/18 11:39:36 gdt Exp $

VERSION_BASE=	4.7.0
# Accomodate testing unreleased versions.
VERSION_RC=
DISTNAME=	tiff-${VERSION_BASE}${VERSION_RC}
CATEGORIES=	graphics
MASTER_SITES=	https://download.osgeo.org/libtiff/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://simplesystems.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files
LICENSE=	mit

WRKSRC=		${WRKDIR}/tiff-${VERSION_BASE}

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_LANGUAGES=		c99 c++
USE_TOOLS=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/tiff
CONFIGURE_ARGS+=	--disable-libdeflate
CONFIGURE_ARGS+=	--disable-sphinx
CONFIGURE_ARGS+=	--disable-webp
CONFIGURE_ARGS+=	--disable-zstd

PKGCONFIG_OVERRIDE=	libtiff-4.pc.in

# NetBSD 10 amd64: pass except 4 cases, because it uses non-POSIX diff -Z
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
