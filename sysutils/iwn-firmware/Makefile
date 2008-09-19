# $NetBSD: Makefile,v 1.1.1.1 2008/09/19 19:04:36 joerg Exp $
#

DISTNAME=		iwlwifi-4965-ucode-${PKG_VERSION}
PKGNAME=		iwn-firmware-${PKG_VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		http://intellinuxwireless.org/iwlwifi/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://intellinuxwireless.org/
COMMENT=		Firmware binary image for the iwn(4) driver

PKG_DESTDIR_SUPPORT=	user-destdir

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
