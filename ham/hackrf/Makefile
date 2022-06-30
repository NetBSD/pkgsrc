# $NetBSD: Makefile,v 1.12 2022/06/30 11:18:30 nia Exp $

DISTNAME=		hackrf-2021.03.1
PKGREVISION=		1
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
USE_TOOLS=		pkg-config

# Suppress warning for developer
CMAKE_ARGS+=		-Wno-dev
CMAKE_ARGS+=		-DLIBUSB_INCLUDE_DIR=${PREFIX}/include/libusb-1.0

CONFIGURE_DIRS=		host
AUTO_MKDIRS=		yes

REPLACE_PYTHON+=	hardware/test/si5351-configure.py
REPLACE_PYTHON+=	firmware/tools/check_clock.py
REPLACE_PYTHON+=	firmware/tools/dump_cgu.py
REPLACE_PYTHON+=	hardware/lollipop/lollipop_logic.py

# suppress warning: "executable bit is set on non-executable file"
pre-patch:
	(cd ${WRKSRC}; find firmware* -type f -perm  0755 | xargs chmod 0644)

post-install:
#	(${MKDIR} ${DESTDIR}${PREFIX}/share/hackerRF )
	(cd ${WRKSRC}; tar cf - \
	COPYING  RELEASENOTES Readme.md TRADEMARK doc firmware firmware-bin hardware |\
	(cd ${DESTDIR}${PREFIX}/share/hackerRF ; tar xf - ) )

.include "../../lang/python/application.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
