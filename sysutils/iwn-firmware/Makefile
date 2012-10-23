# $NetBSD: Makefile,v 1.2 2012/10/23 19:51:09 asau Exp $
#

DISTNAME=		iwlwifi-4965-ucode-${PKG_VERSION}
PKGNAME=		iwn-firmware-${PKG_VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		http://intellinuxwireless.org/iwlwifi/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://intellinuxwireless.org/
COMMENT=		Firmware binary image for the iwn(4) driver

NO_CONFIGURE=		yes
NO_BUILD=		yes

PKG_VERSION=		4.44.1.20
FIRMNAME=		iwlwifi-4965.ucode

INSTALLATION_DIRS=	libdata/if_iwn

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.iwlwifi-4965-ucode ${DESTDIR}${PREFIX}/libdata/if_iwn
	${INSTALL_DATA} ${WRKSRC}/README.iwlwifi-4965-ucode ${DESTDIR}${PREFIX}/libdata/if_iwn
	${INSTALL_DATA} ${WRKSRC}/iwlwifi-4965-1.ucode ${DESTDIR}${PREFIX}/libdata/if_iwn/${FIRMNAME}

.include "../../mk/bsd.pkg.mk"
