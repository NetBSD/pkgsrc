# $NetBSD: Makefile,v 1.12 2018/09/01 19:09:57 gdt Exp $

DISTNAME=		rtl-sdr-0.5.4
CATEGORIES=		ham
MASTER_SITES=		${MASTER_SITE_GITHUB:=steve-m/}
GITHUB_PROJECT=		librtlsdr
GITHUB_TAG=		v${PKGVERSION_NOREV}

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

SUBST_CLASSES+=			fix-inline
SUBST_STAGE.fix-inline=		pre-configure
SUBST_MESSAGE.fix-inline=	Fixing inline calls
SUBST_FILES.fix-inline=		src/rtl_adsb.c src/rtl_power.c
SUBST_SED.fix-inline=		-e 's,inline,static inline,g'

PKGCONFIG_OVERRIDE+=     librtlsdr.pc.in

LDFLAGS.SunOS+=		-lsocket -lnsl

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
