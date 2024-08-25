# $NetBSD: Makefile,v 1.18 2024/08/25 06:18:54 wiz Exp $

DISTNAME=	hackrf-2024.02.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=mossmann/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://greatscottgadgets.com/hackrf/
COMMENT=	HackRF, an open source SDR hardware platform
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

CONFIGURE_DIR=	host
CMAKE_CONFIGURE_ARGS+=	-DLIBUSB_INCLUDE_DIR=${PREFIX}/include/libusb-1.0

INSTALLATION_DIRS+=	share/hackerRF

REPLACE_PYTHON+=	firmware/tools/check_clock.py
REPLACE_PYTHON+=	firmware/tools/cpld_bitstream.py
REPLACE_PYTHON+=	firmware/tools/dump_cgu.py
REPLACE_PYTHON+=	hardware/lollipop/lollipop_logic.py
REPLACE_PYTHON+=	hardware/test/si5351-configure.py

# suppress warning: "executable bit is set on non-executable file"
pre-patch:
	${FIND} ${WRKSRC}/firmware ${WRKSRC}/firmware-bin \
		-type f -perm 0755 -exec chmod 0644 {} \;

post-install:
.for dir in doc firmware firmware-bin hardware
	cd ${WRKSRC} && ${PAX} -rw ${dir} ${DESTDIR}${PREFIX}/share/hackerRF
.endfor

.include "../../devel/cmake/build.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
