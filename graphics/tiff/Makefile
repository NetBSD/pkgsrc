# $NetBSD: Makefile,v 1.75 2006/02/20 17:56:36 joerg Exp $

DISTNAME=	tiff-3.8.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://libtiff.maptools.org/dl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.remotesensing.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--enable-cxx
# next line shouldn't be necessary, but 3.8.0 doesn't
# compile correctly without it
CONFIGURE_ARGS+=	--with-default-strip-size=8192
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/tiff

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
