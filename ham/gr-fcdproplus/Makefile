# $NetBSD: Makefile,v 1.1 2014/10/13 13:07:13 mef Exp $

DISTNAME=		gr-fcdproplus_3.7.11.orig
PKGNAME=		${DISTNAME:S/_/-/S/.orig//}
CATEGORIES=		ham
MASTER_SITES+=		${MASTER_SITE_DEBIAN:=pool/main/g/gr-fcdproplus/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dl1ksv/gr-fcdproplus
COMMENT=		Addon for funcube dongle pro+ to GNU Radio
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CXXFLAGS+=		-I${PREFIX}/include/libusb-1.0

# Suppress warning for developer
CMAKE_ARGS+=		-Wno-dev
CMAKE_ARGS+=		-DGNURADIO_RUNTIME_INCLUDE_DIRS=${PREFIX}/include
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}

SUBST_CLASSES+=		libusb
SUBST_FILES.libusb+=	CMakeLists.txt
SUBST_STAGE.libusb=	pre-configure
SUBST_SED.libusb=	-e 's,@@PREFIX@@,${PREFIX},'
SUBST_MESSAGE.libusb=	Fix for "libusb.h not found"

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../lang/python/application.mk"
.include	"../../lang/python/pyversion.mk"
.include 	"../../ham/gnuradio-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
