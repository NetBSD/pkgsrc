# $NetBSD: Makefile,v 1.65 2005/01/13 15:39:20 jlam Exp $

DISTNAME=	tiff-3.7.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://libtiff.maptools.org/dl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.remotesensing.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-rpath

.include "../../mk/bsd.prefs.mk"

.if defined(USE_GIF) && !empty(USE_GIF:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	lzw
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.tiff
PKG_SUPPORTED_OPTIONS=	lzw
.include "../../mk/bsd.options.mk"

###
### LZW compression support
###
.if !empty(PKG_OPTIONS:Mlzw)
CONFIGURE_ARGS+=	--enable-lzw
.else
CONFIGURE_ARGS+=	--disable-lzw
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

# We explicitly build libtiff without C++ support by patching the
# configure script (patch-af).  We also add a new target into
# libtiff/Makefile to create a libtiffcxx.la containing the C++
# functions (patch-ag).
#
post-build:
	cd ${WRKSRC}/libtiff && ${MAKE} libtiffcxx.la

post-install:
	cd ${WRKSRC}/libtiff && ${INSTALL_DATA} tiffio.hxx ${PREFIX}/include
	cd ${WRKSRC}/libtiff && ${LIBTOOL} --mode=install		\
		${INSTALL_LIB} libtiffcxx.la ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
