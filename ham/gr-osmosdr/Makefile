# $NetBSD: Makefile,v 1.68 2025/09/27 09:57:24 wiz Exp $

DISTNAME=	gr-osmosdr-0.2.6
PKGREVISION=	8
CATEGORIES=	ham
# main git repo doesn't allow snapshots to be downloaded
#MASTER_SITES=	https://git.osmocom.org/gr-osmosdr/snapshot/
MASTER_SITES=	${MASTER_SITE_GITHUB:=osmocom/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.osmocom.org/gr-osmosdr
COMMENT=	SDR Hardware support for OsmoSDR and so many more
LICENSE=	gnu-gpl-v2

# for docs/doxygen/update_pydoc.py
TOOL_DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11 filesystem
# NB: If gnuradio-core and gr-osmosdr are built with gcc10/gc12 or
# gcc12/gcc10, then "import osmosdr" in python will fail with
# not-found symbol apparently due to c++ ABI issues.  No accommodations
# are in place for this, as "mixing gcc versions with c++ leads to UB"
# is already well known.

.include "../../devel/cmake/build.mk"
# Suppress warning for developer
CMAKE_CONFIGURE_ARGS+=	-Wno-dev
# TODO: make it PKG_OPTION
CMAKE_CONFIGURE_ARGS+=	-DENABLE_DOXYGEN=OFF
CMAKE_CONFIGURE_ARGS+=	-Dpybind11_DIR=${PREFIX}/${PYSITELIB}/pybind11/share/cmake/pybind11

PLIST_SUBST+=	PYSITELIB=${PYSITELIB}

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

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
