# $NetBSD: Makefile,v 1.1.1.1 2008/12/11 21:18:41 reed Exp $
#

DISTNAME=	wpa_supplicant-0.6.6
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://hostap.epitest.fi/wpa_supplicant/
COMMENT=	Wireless connection client daemon for WPA, WPA2, and WEP

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

post-extract:
	cp ${FILESDIR}/defconfig.${OPSYS} ${WRKSRC}/wpa_supplicant/.config

do-build:
	cd ${WRKSRC}/wpa_supplicant && ${SETENV} ${MAKE_ENV} ${GMAKE} all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_supplicant/wpa_cli \
		${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_supplicant/wpa_passphrase \
		${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_supplicant/wpa_supplicant \
		${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/wpa_supplicant/doc/docbook/wpa_supplicant.conf.5 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN} ${WRKSRC}/wpa_supplicant/doc/docbook/wpa_cli.8 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/wpa_supplicant/doc/docbook/wpa_passphrase.8 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/wpa_supplicant/doc/docbook/wpa_supplicant.8 \
		${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8/

.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
