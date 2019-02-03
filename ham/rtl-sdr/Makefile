# $NetBSD: Makefile,v 1.14 2019/02/03 10:48:17 tnn Exp $

DISTNAME=		rtl-sdr-0.6.0
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

USE_CMAKE=		yes
CONFIGURE_DIRS=build
BUILD_DIRS=${CONFIGURE_DIRS}
CMAKE_ARG_PATH=..

PKGCONFIG_OVERRIDE+=     librtlsdr.pc.in

LDFLAGS.SunOS+=		-lsocket -lnsl

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
