# $NetBSD: Makefile,v 1.14 2023/01/30 17:56:38 adam Exp $

DISTNAME=		hackrf-2022.09.1
CATEGORIES=		ham
MASTER_SITES=		${MASTER_SITE_GITHUB:=mossmann/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://greatscottgadgets.com/hackrf/
#OMEPAGE=		https://www.kickstarter.com/projects/mossmann/hackrf-an-open-source-sdr-platform
COMMENT=		HackRF, an open source SDR hardware platform
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
USE_TOOLS=		pkg-config tar

# Suppress warning for developer
CMAKE_ARGS+=		-Wno-dev
CMAKE_ARGS+=		-DLIBUSB_INCLUDE_DIR=${PREFIX}/include/libusb-1.0

CONFIGURE_DIRS=		host
AUTO_MKDIRS=		yes

REPLACE_PYTHON+=	firmware/tools/check_clock.py
REPLACE_PYTHON+=	firmware/tools/cpld_bitstream.py
REPLACE_PYTHON+=	firmware/tools/dump_cgu.py
REPLACE_PYTHON+=	hardware/lollipop/lollipop_logic.py
REPLACE_PYTHON+=	hardware/test/si5351-configure.py

# suppress warning: "executable bit is set on non-executable file"
pre-patch:
	(cd ${WRKSRC}; find firmware* -type f -perm  0755 | xargs chmod 0644)

post-install:
	(cd ${WRKSRC}; tar cf - \
	COPYING  RELEASENOTES Readme.md doc firmware firmware-bin hardware |\
	(cd ${DESTDIR}${PREFIX}/share/hackerRF ; tar xf - ) )

.include "../../lang/python/application.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
