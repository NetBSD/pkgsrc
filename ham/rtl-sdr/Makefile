# $NetBSD: Makefile,v 1.1 2014/10/13 13:05:36 mef Exp $
#
DISTNAME=		v0.5.3
PKGNAME=		rtl-sdr-${DISTNAME:S/v//}
CATEGORIES=		ham
MASTER_SITES=		-https://github.com/steve-m/librtlsdr/archive/${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/rtl-sdr
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
LICENSE=		gnu-gpl-v2

DIST_SUBDIR=		rtl-sdr
USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake
USE_CMAKE=		yes
WRKSRC=			${WRKDIR}/librtlsdr-${DISTNAME:S/v//}
AUTO_MKDIRS=		yes

## CMake Error at CMakeLists.txt:69 (message):
##   LibUSB 1.0 required to compile rtl-sdr
CMAKE_ARGS+=	-DLIBUSB_INCLUDE_DIR=${PREFIX}/include/libusb-1.0
CMAKE_ARG_PATH= 	../
CONFIGURE_DIRS=		build

SUBST_CLASSES+=		destdir
SUBST_MESSAGE.destdir=	Replace install destination to ${DESTDIR}
SUBST_FILES.destdir=	build/cmake_install.cmake
SUBST_STAGE.destdir=	pre-install
SUBST_SED.destdir=	-e 's|\$${CMAKE_INSTALL_PREFIX}|${DESTDIR}\$${CMAKE_INSTALL_PREFIX}|'

pre-configure:
	(cd ${WRKSRC}; ${MKDIR} build;)

do-build:
	(cd ${WRKSRC}/build; ${GMAKE})

do-install:
	(cd ${WRKSRC}/build; ${GMAKE} install)

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
