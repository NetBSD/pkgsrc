# $NetBSD: Makefile,v 1.61 2004/12/28 23:10:10 reed Exp $

DISTNAME=	tiff-3.7.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://libtiff.maptools.org/dl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.remotesensing.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

BUILD_DEFS+=	USE_GIF

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-rpath

.include "../../mk/bsd.prefs.mk"

.if !defined(USE_GIF) || !empty(USE_GIF:M[Nn][Oo])
# disable support for LZW algorithm
CONFIGURE_ARGS+=	--disable-lzw
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
