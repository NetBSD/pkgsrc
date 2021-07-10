# $NetBSD: Makefile,v 1.16 2021/07/10 16:48:00 dholland Exp $

DISTNAME=		rtl-sdr-0.6.0
PKGREVISION=		1
CATEGORIES=		ham
MASTER_SITES=		${MASTER_SITE_GITHUB:=steve-m/}
GITHUB_PROJECT=		librtlsdr
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/rtl-sdr
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
LICENSE=		gnu-gpl-v2

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config

USE_CMAKE=	yes
CONFIGURE_DIRS=	build
BUILD_DIRS=	${CONFIGURE_DIRS}
CMAKE_ARG_PATH=	..

PKGCONFIG_OVERRIDE+=	librtlsdr.pc.in

LDFLAGS.SunOS+=		-lsocket -lnsl
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-configure:
	${MKDIR} ${WRKSRC}/build


PAGES=		rtl_adsb.1 rtl_eeprom.1 rtl_fm.1 rtl_power.1 rtl_sdr.1 \
		rtl_tcp.1 rtl_test.1
post-install:
.for i in ${PAGES}
	${INSTALL} ${WRKSRC}/debian/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
