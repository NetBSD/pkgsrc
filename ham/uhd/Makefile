# $NetBSD: Makefile,v 1.68 2022/06/30 11:18:30 nia Exp $

DISTNAME=	uhd-4.1.0.5
PKGREVISION=	2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=EttusResearch/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EttusResearch/uhd
COMMENT=	USRP (Universal Software Radio Peripheral) Hardware Drivers
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

CMAKE_ARGS+=	-DLIB_SUFFIX=""
CMAKE_ARGS+=	-DENABLE_MAN_PAGE_COMPRESSION=OFF
CMAKE_ARGS+=	-DPKG_MAN_DIR=${PKGMANDIR}/man1
CMAKE_ARGS+=	-DRST2HTML_EXECUTABLE=${PREFIX}/bin/rst2html-${PYVERSSUFFIX}.py
CMAKE_ARGS+=	-Wno-dev
.include "../../lang/python/pyversion.mk"
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN}
.if !empty(_PYTHON_VERSION:M3*)
CMAKE_ARGS+=	-DENABLE_PYTHON3=ON
.endif

# Upstream says C++11 is required, even though it is not documented.
# It is documented that gcc 4.8 is required, when using gcc.
# https://github.com/EttusResearch/uhd/issues/236
#
# Upstream does not seem to have any documentation that gnu++11 is
# required, but it builds with tha and not with c++11 on netbsd-8.  No
# ticket filed because #236 resulted in in-ticket clarification only
# (and not a doc edit), and having experimented no clarification is
# needed.
USE_CMAKE=		yes
USE_LANGUAGES=		c gnu++14
USE_TOOLS+=		pkg-config
GCC_REQD+=		4.8
# to avoid extra pax_global_header
EXTRACT_USING=		gtar
WRKSRC=			${WRKDIR}/${DISTNAME}/host

# The files with their name uhd-xxxx, are moved down from uhd/xxxx for this process.
REPLACE_PYTHON+=	utils/convert_cal_data.py
REPLACE_PYTHON+=	utils/converter_benchmark.py
REPLACE_PYTHON+=	utils/latency/graph.py
REPLACE_PYTHON+=	utils/latency/run_tests.py
REPLACE_PYTHON+=	utils/rfnoc_image_builder.py
REPLACE_PYTHON+=	utils/uhd_images_downloader.py.in
REPLACE_PYTHON+=	utils/uhd_power_cal.py
REPLACE_PYTHON+=	utils/usrp2_card_burner.py
REPLACE_PYTHON+=	utils/usrp2_card_burner_gui.py
REPLACE_PYTHON+=	utils/usrp2_recovery.py
REPLACE_PYTHON+=	tests/devtest/benchmark_rate_test.py
REPLACE_PYTHON+=	tests/devtest/multi_usrp_test.py
REPLACE_PYTHON+=	tests/devtest/python_api_test.py
REPLACE_PYTHON+=	tests/devtest/python_rx_stability_test.py
REPLACE_PYTHON+=	tests/devtest/run_testsuite.py
REPLACE_PYTHON+=	tests/devtest/recv_stability_test.py
REPLACE_PYTHON+=	tests/devtest/rx_samples_to_file_test.py
REPLACE_PYTHON+=	tests/devtest/test_messages_test.py
REPLACE_PYTHON+=	tests/devtest/test_pps_test.py
REPLACE_PYTHON+=	tests/devtest/tx_bursts_test.py
REPLACE_PYTHON+=	tests/devtest/tx_waveforms_test.py
REPLACE_PYTHON+=	tests/devtest/uhd_test_base.py
REPLACE_PYTHON+=	tests/devtest/usrp_probe.py
REPLACE_PYTHON+=	tests/devtest/usrp_probe_test.py
REPLACE_PYTHON+=	tests/streaming_performance/batch_run_benchmark_rate.py
REPLACE_PYTHON+=	tests/streaming_performance/run_E3xx_max_rate_tests.py
REPLACE_PYTHON+=	tests/streaming_performance/run_N3xx_max_rate_tests.py
REPLACE_PYTHON+=	tests/streaming_performance/run_X3xx_max_rate_tests.py

# -pthread needed to turn on boost threads on some platforms
CXXFLAGS.SunOS+=	-pthread
LDFLAGS.SunOS+=		-lsocket

INSTALLATION_DIRS+=	share/uhd
INSTALLATION_DIRS+=	share/uhd/firmware
INSTALLATION_DIRS+=	share/uhd/fpga
INSTALLATION_DIRS+=	share/uhd/images

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
