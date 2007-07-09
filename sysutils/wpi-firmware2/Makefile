# $NetBSD: Makefile,v 1.1.1.1 2007/07/09 19:16:23 degroote Exp $
#

VERSION=		2.14.3
DISTNAME=		iwlwifi-3945-ucode-${VERSION}
PKGNAME=		wpi-firmware2-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		http://intellinuxwireless.org/iwlwifi/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://intellinuxwireless.org/
COMMENT=		Firmware binary images for wpi(4) driver

NO_CONFIGURE=		yes
NO_BUILD=		yes


DATA_DESTDIR=${PREFIX}/libdata/if_wpi

do-install:
	${INSTALL_DATA_DIR} ${DATA_DESTDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.iwlwifi-3945-ucode  ${DATA_DESTDIR}
	${INSTALL_DATA} ${WRKSRC}/README.iwlwifi-3945-ucode ${DATA_DESTDIR}
	${INSTALL_DATA} ${WRKSRC}/iwlwifi-3945.ucode ${DATA_DESTDIR}

.include "../../mk/bsd.pkg.mk"
