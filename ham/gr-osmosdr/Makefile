# $NetBSD: Makefile,v 1.38 2022/01/10 01:46:37 ryoon Exp $

DISTNAME=		gr-osmosdr-0.2.3.20210128
PKGREVISION=		5
CATEGORIES=		ham
# main git repo doesn't allow snapshots to be downloaded
#MASTER_SITES=		https://git.osmocom.org/gr-osmosdr/snapshot/
MASTER_SITES=		${MASTER_SITE_GITHUB:=osmocom/}
GITHUB_TAG=		a100eb024c0210b95e4738b6efd836d48225bd03

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://git.osmocom.org/gr-osmosdr
COMMENT=		SDR Hardware support for OsmoSDR and so many more
LICENSE=		gnu-gpl-v2

# for docs/doxygen/update_pydoc.py
BUILD_DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

# Suppress warning for developer
CMAKE_ARGS+=	-Wno-dev
# TODO: make it PKG_OPTION
CMAKE_ARGS+=	-DENABLE_DOXYGEN=OFF
CMAKE_ARGS+=	-Dpybind11_DIR=${PREFIX}/${PYSITELIB}/pybind11/share/cmake/pybind11

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		apps/osmocom_siggen_base.py

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/gnuradio-uhd/buildlink3.mk"
.include "../../ham/hackrf/buildlink3.mk"
.include "../../ham/rtl-sdr/buildlink3.mk"
.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../ham/uhd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
