# $NetBSD: Makefile,v 1.7 2011/10/26 19:28:00 gls Exp $
#

DISTNAME=	podofo-0.9.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=podofo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://podofo.sourceforge.net/
COMMENT=	Library to work with the PDF file format
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DFREETYPE_INCLUDE_DIR_FT2BUILD:PATH=${BUILDLINK_PREFIX.freetype2}/include
CMAKE_ARGS+=	-DFREETYPE_LIB_PATHS:PATH=${BUILDLINK_PREFIX.freetype2}/lib
CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

.include "options.mk"

# tests-depend on cppunit (for unit tests)
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
