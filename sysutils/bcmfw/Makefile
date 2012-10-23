# $NetBSD: Makefile,v 1.7 2012/10/23 19:50:52 asau Exp $

DISTNAME=		bcmfw-1.0
CATEGORIES=		sysutils
MASTER_SITES=		http://homepages.rya-online.net/plunky/
DISTFILES=		bcmfw-1.0.tar.gz		\
			bluez-firmware-1.2.tar.gz
SITES.bluez-firmware-1.2.tar.gz= \
			http://bluez.sourceforge.net/download/

MAINTAINER=		plunky@rya-online.net
COMMENT=		Broadcom 2033 Bluetooth Firmware Loader
LICENSE=		bcmfw-license

RESTRICTED=		No clear permission redistribute firmware
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-[4-9].*-*

RCD_SCRIPTS+=		bcmfw

FIRMWARE_DIR=		libdata/bcmfw

INSTALLATION_DIRS=	${PKGMANDIR}/man8 ${FIRMWARE_DIR} sbin

PLIST_SUBST+=		FIRMWARE_DIR=${FIRMWARE_DIR}

SUBST_CLASSES+=		dir
SUBST_FILES.dir=	bcmfw.8 bcmfw.c
SUBST_SED.dir=		-e 's,BCM2033-,${PREFIX}/${FIRMWARE_DIR}/&,'
SUBST_STAGE.dir=	post-patch
SUBST_MESSAGE.dir=	Fixing path to firmware directory.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bcmfw ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bcmfw.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKDIR}/bluez-firmware-1.2/broadcom/BCM-LEGAL.txt ${DESTDIR}${PREFIX}/${FIRMWARE_DIR}
	${INSTALL_DATA} ${WRKDIR}/bluez-firmware-1.2/broadcom/BCM2033-FW.bin ${DESTDIR}${PREFIX}/${FIRMWARE_DIR}
	${INSTALL_DATA} ${WRKDIR}/bluez-firmware-1.2/broadcom/BCM2033-MD.hex ${DESTDIR}${PREFIX}/${FIRMWARE_DIR}

.include "../../mk/bsd.pkg.mk"
