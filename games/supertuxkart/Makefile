# $NetBSD: Makefile,v 1.8 2014/01/01 02:46:49 ryoon Exp $
#

DISTNAME=	supertuxkart-0.8.1-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=supertuxkart/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supertuxkart.sourceforge.net/
COMMENT=	Free 3D kart racing game
#LICENSE=	gnu-gpl-v3 AND Creative-Commons-Attribution AND Creative-Commons-BY-SA AND Creative-Commons-Sampling+ AND FreeArt License AND SoundSnap license AND Public Domain AND Image*After terms

WRKSRC=			${WRKDIR}/SuperTuxKart-0.8.1
USE_CMAKE=		yes
#USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_JPEG_LIB_=1
CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_LIB_PNG_=1
CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_ZLIB_=1
CXXFLAGS+=	-DNO_IRR_USE_NON_SYSTEM_BZLIB_=1

# Debug nob for STK
#CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug

SUBST_CLASSES+=		dos_eol
SUBST_MESSAGE.dos_eol=	Removing DOS line-ends
SUBST_STAGE.dos_eol=	post-extract
SUBST_FILES.dos_eol=	lib/irrlicht/source/Irrlicht/Makefile
SUBST_FILES.dos_eol+=	lib/irrlicht/source/Irrlicht/os.cpp
SUBST_FILES.dos_eol+=	lib/irrlicht/source/Irrlicht/COSOperator.cpp
SUBST_FILES.dos_eol+=	lib/irrlicht/source/Irrlicht/CIrrDeviceLinux.cpp
SUBST_FILTER_CMD.dos_eol=	${TR} -d '\r'

CMAKE_ARGS+=	-DUSE_WIIUSE=OFF
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
SUBST_CLASSES+=		js
SUBST_STAGE.js=		pre-configure
SUBST_MESSAGE.js=	Disable Linux joystick support.
SUBST_FILES.js+=	lib/irrlicht/include/IrrCompileConfig.h
SUBST_SED.js+=		-e '/define.*_IRR_COMPILE_WITH_JOYSTICK_EVENTS_/d'
.endif

# for irrlicht debugging
#pre-build:
#	cd ${WRKSRC}/lib/irrlicht/source/Irrlicht && \
#		${MAKE_ENV} DEBUG=1 make ${_MAKE_JOBS}

pre-build:
	cd ${WRKSRC}/lib/irrlicht/source/Irrlicht && \
		${MAKE_ENV} NDEBUG=1 make ${_MAKE_JOBS}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
