# $NetBSD: Makefile,v 1.48 2019/07/01 04:08:26 ryoon Exp $

DISTNAME=	uhd-3.14.0.0
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=EttusResearch/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EttusResearch/uhd
COMMENT=	USRP (Universal Software Radio Peripheral) Hardware Drivers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

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
USE_LANGUAGES=		c gnu++11
USE_TOOLS+=		pkg-config
GCC_REQD+=		4.8
# to avoid extra pax_global_header
EXTRACT_USING=		gtar
WRKSRC=			${WRKDIR}/${DISTNAME}/host

# The files with their name uhd-xxxx, are moved down from uhd/xxxx for this process.
REPLACE_PYTHON+=	utils/converter_benchmark.py
REPLACE_PYTHON+=	utils/latency/graph.py
REPLACE_PYTHON+=	utils/latency/run_tests.py
REPLACE_PYTHON+=	utils/uhd_images_downloader.py.in
REPLACE_PYTHON+=	utils/usrp2_card_burner.py
REPLACE_PYTHON+=	utils/usrp2_card_burner_gui.py
REPLACE_PYTHON+=	tests/devtest/benchmark_rate_test.py
REPLACE_PYTHON+=	tests/devtest/multi_usrp_test.py
REPLACE_PYTHON+=	tests/devtest/python_api_test.py
REPLACE_PYTHON+=	tests/devtest/run_testsuite.py
REPLACE_PYTHON+=	tests/devtest/rx_samples_to_file_test.py
REPLACE_PYTHON+=	tests/devtest/test_messages_test.py
REPLACE_PYTHON+=	tests/devtest/test_pps_test.py
REPLACE_PYTHON+=	tests/devtest/tx_bursts_test.py
REPLACE_PYTHON+=	tests/devtest/uhd_test_base.py
REPLACE_PYTHON+=	tests/devtest/usrp_probe.py
REPLACE_PYTHON+=	tests/devtest/usrp_probe_test.py

INSTALLATION_DIRS+=	share/uhd
INSTALLATION_DIRS+=	share/uhd/firmware
INSTALLATION_DIRS+=	share/uhd/fpga
INSTALLATION_DIRS+=	share/uhd/images

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Convert share/man to man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	docs/CMakeLists.txt
SUBST_SED.man=		-e '/UHD_INSTALL/s,$${PKG_MAN_DIR},${PREFIX}/${PKGMANDIR}/man1,'
# UHD_INSTALL(FILES ${gzfile} DESTINATION ${PKG_MAN_DIR} COMPONENT manpages)

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
