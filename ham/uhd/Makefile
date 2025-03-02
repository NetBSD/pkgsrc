# $NetBSD: Makefile,v 1.85 2025/03/02 09:07:27 wiz Exp $

DISTNAME=	uhd-4.8.0.0
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=EttusResearch/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/EttusResearch/uhd
COMMENT=	USRP (Universal Software Radio Peripheral) Hardware Drivers
LICENSE=	gnu-gpl-v3

# to avoid extra pax_global_header
EXTRACT_USING=	gtar
WRKSRC=		${WRKDIR}/${DISTNAME}/host

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mako>=0.4.2:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15:../../devel/py-ruamel-yaml

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=	-DLIB_SUFFIX=""
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MAN_PAGE_COMPRESSION=OFF
CMAKE_CONFIGURE_ARGS+=	-DPKG_MAN_DIR=${PKGMANDIR}/man1
CMAKE_CONFIGURE_ARGS+=	-DRST2HTML_EXECUTABLE=${PREFIX}/bin/rst2html-${PYVERSSUFFIX}.py
CMAKE_CONFIGURE_ARGS+=	-Wno-dev

.include "../../lang/python/pyversion.mk"

CMAKE_CONFIGURE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN}
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PYTHON3=ON

PY_PATCHPLIST=	yes

# The files with their name uhd-xxxx, are moved down from uhd/xxxx for this process.
REPLACE_PYTHON+=	../mpm/python/usrp_hwd.py
REPLACE_PYTHON+=	examples/python/*.py
REPLACE_PYTHON+=	tests/devtest/*.py
REPLACE_PYTHON+=	tests/streaming_performance/*.py
REPLACE_PYTHON+=	utils/*.py
REPLACE_PYTHON+=	utils/latency/*.py

# -pthread needed to turn on boost threads on some platforms
CXXFLAGS.SunOS+=	-pthread
LDFLAGS.SunOS+=		-lsocket

INSTALLATION_DIRS+=	share/uhd
INSTALLATION_DIRS+=	share/uhd/firmware
INSTALLATION_DIRS+=	share/uhd/fpga
INSTALLATION_DIRS+=	share/uhd/images

MODULE_VERSION=		${PKGVERSION_NOREV:C/\.[0-9]$//}
PLIST_SUBST+=		MODULE_VERSION=${MODULE_VERSION}

.include "options.mk"

.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/uhd/libpyuhd.so \
		${DESTDIR}${PREFIX}/${PYSITELIB}/uhd/libpyuhd.so
.else
PLIST_SRC+=	PLIST.x4xx
.endif

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/atomic64.mk"
FAKE_NCURSES=	yes
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
