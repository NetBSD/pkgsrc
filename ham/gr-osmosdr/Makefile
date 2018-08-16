# $NetBSD: Makefile,v 1.12 2018/08/16 18:54:56 adam Exp $

DISTNAME=		gr-osmosdr-0.1.4
PKGREVISION=		9
CATEGORIES=		ham
MASTER_SITES+=		http://git.osmocom.org/gr-osmosdr/snapshot/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://git.osmocom.org/gr-osmosdr
COMMENT=		SDR Hardware support for OsmoSDR and so many more
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

# Suppress warning for developer
CMAKE_ARGS+=	-Wno-dev
# --   * Ettus USRP Devices
CMAKE_ARGS+=	-DGNURADIO_UHD_INCLUDE_DIRS=${PREFIX}/include/uhd
CMAKE_ARGS+=	-DGNURADIO_BLOCKS_INCLUDE_DIRS=${PREFIX}/include

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

REPLACE_PYTHON+=	apps/osmocom_siggen_base.py

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../devel/orc/buildlink3.mk"

.include	"../../ham/uhd/buildlink3.mk"
.include	"../../lang/python/application.mk"
.include	"../../lang/python/extension.mk"

.include	"../../ham/rtl-sdr/buildlink3.mk"
.include	"../../ham/libmirisdr/buildlink3.mk"
.include	"../../ham/osmo-sdr/buildlink3.mk"
.include	"../../ham/gr-fcdproplus/buildlink3.mk"
.include	"../../ham/hackrf/buildlink3.mk"

.include	"../../ham/gnuradio-core/buildlink3.mk"
.include	"../../ham/gnuradio-fcd/buildlink3.mk"
.include	"../../ham/gnuradio-uhd/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
