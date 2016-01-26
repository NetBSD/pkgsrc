# $NetBSD: Makefile,v 1.5 2016/01/26 09:10:39 dbj Exp $

DISTNAME=		rtl-sdr-0.5.3
PKGREVISION=		1
CATEGORIES=		ham
MASTER_SITES=		${MASTER_SITE_GITHUB:=steve-m/}
GITHUB_PROJECT=		librtlsdr
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/rtl-sdr
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
LICENSE=		gnu-gpl-v2

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake

USE_CMAKE=		yes
CONFIGURE_DIRS=build
BUILD_DIRS=${CONFIGURE_DIRS}
CMAKE_ARG_PATH=..

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
