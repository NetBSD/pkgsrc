# $NetBSD: Makefile,v 1.4 2012/10/23 19:51:35 asau Exp $
#

VERSION=		2.14.4
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

INSTALLATION_DIRS=	libdata/if_wpi

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.iwlwifi-3945-ucode  ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/README.iwlwifi-3945-ucode  ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/iwlwifi-3945.ucode  ${DESTDIR}${PREFIX}/libdata/if_wpi

.include "../../mk/bsd.pkg.mk"
