# $NetBSD: Makefile,v 1.21 2024/08/18 18:57:36 gdt Exp $

DISTNAME=		rtl-sdr-2.0.1
CATEGORIES=		ham
MASTER_SITES=		${MASTER_SITE_GITHUB:=osmocom/}
GITHUB_TAG=		refs/tags/v${PKGVERSION_NOREV}
# There are multiple upstreams:
#   https://gitea.osmocom.org/sdr/rtl-sdr/ (official sources)
#   https://github.com/osmocom/rtl-sdr (official mirror)
#   https://github.com/steve-m/librtlsdr
#   https://github.com/librtlsdr/librtlsdr (forked from steve-m)

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		https://osmocom.org/projects/rtl-sdr/wiki
COMMENT=		Turns your Realtek RTL2832 based DVB dongle into a SDR receiver
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config

.include "../../devel/cmake/build.mk"

PKGCONFIG_OVERRIDE+=	librtlsdr.pc.in

LDFLAGS.SunOS+=		-lsocket -lnsl
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PAGES=		rtl_adsb.1 rtl_eeprom.1 rtl_fm.1 rtl_power.1 rtl_sdr.1 \
		rtl_tcp.1 rtl_test.1
post-install:
.for i in ${PAGES}
	${INSTALL} ${WRKSRC}/debian/${i} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
