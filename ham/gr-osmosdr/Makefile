# $NetBSD: Makefile,v 1.29 2020/12/14 00:41:57 dbj Exp $

DISTNAME=		gr-osmosdr-0.2.2
CATEGORIES=		ham
# main git repo doesn't allow snapshots to be downloaded
#MASTER_SITES=		https://git.osmocom.org/gr-osmosdr/snapshot/
MASTER_SITES=		${MASTER_SITE_GITHUB:=osmocom/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://git.osmocom.org/gr-osmosdr
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
# TODO: make it PKG_OPTION
CMAKE_ARGS+=	-DENABLE_DOXYGEN=OFF

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

PYTHON_VERSIONS_ACCEPTED=	37 38
REPLACE_PYTHON+=		apps/osmocom_siggen_base.py

.include	"../../devel/boost-headers/buildlink3.mk"
.include	"../../devel/boost-libs/buildlink3.mk"
.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../devel/orc/buildlink3.mk"

# \todo Clearly threre is some ordering scheme.  Explain it.

.include	"../../ham/uhd/buildlink3.mk"
.include	"../../lang/python/application.mk"

.include	"../../ham/rtl-sdr/buildlink3.mk"
.include	"../../ham/hackrf/buildlink3.mk"
.include	"../../ham/soapy-sdr/buildlink3.mk"

.include	"../../ham/gnuradio-core/buildlink3.mk"
.include	"../../ham/gnuradio-uhd/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
