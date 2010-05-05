# $NetBSD: Makefile,v 1.4 2010/05/05 18:23:52 drochner Exp $
#

DISTNAME=	podofo-0.7.0
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=podofo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://podofo.sourceforge.net/
COMMENT=	Library to work with the PDF file format
#LICENSE=	gnu-lgpl-v? AND gnu-gpl-v?

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DFREETYPE_INCLUDE_DIR_FT2BUILD:PATH=${BUILDLINK_PREFIX.freetype2}/include
CMAKE_ARGS+=	-DFREETYPE_LIB_PATHS:PATH=${BUILDLINK_PREFIX.freetype2}/lib
CFLAGS+=	-fPIC
CXXFLAGS+=	-fPIC

# XXX lua support should be optional
.include "../../lang/lua/buildlink3.mk"
# tests-depend on cppunit (for unit tests)
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
