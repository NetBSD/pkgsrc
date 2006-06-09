# $NetBSD: Makefile,v 1.78.2.1 2006/06/09 07:29:35 snj Exp $

DISTNAME=	tiff-3.8.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://libtiff.maptools.org/dl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.remotesensing.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--enable-cxx
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/tiff

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
