# $NetBSD: Makefile,v 1.5 2022/12/13 14:20:32 jperkin Exp $

DISTNAME=	irrlicht-1.8.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=irrlicht/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://irrlicht.sourceforge.net/
COMMENT=	Open source high performance real-time 3D engine
LICENSE=	zlib

# Work around NetBSD unzip for patched files.
SUBST_CLASSES+=		cr
SUBST_STAGE.cr=		post-extract
SUBST_FILES.cr+=	source/Irrlicht/COSOperator.cpp
SUBST_FILES.cr+=	source/Irrlicht/Makefile
SUBST_FILES.cr+=	source/Irrlicht/os.cpp
SUBST_FILTER_CMD.cr=	${TR} -d '\r'
SUBST_NOOP_OK.cr=	yes

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

MAKE_ENV+=	NDEBUG=1
BUILD_DIRS=	source/Irrlicht
BUILD_TARGET=	sharedlib

CXXFLAGS+=	-DNO_IRR_COMPILE_WITH_JOYSTICK_EVENTS_=1
CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_JPEG_LIB_=1
CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_LIB_PNG_=1
CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_ZLIB_=1
CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_BZLIB_=1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
