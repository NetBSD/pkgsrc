# $NetBSD: Makefile,v 1.3 2012/10/23 19:51:34 asau Exp $
#

DISTNAME=		ipw3945-ucode-1.13
PKGNAME=		wpi-firmware-1.13
CATEGORIES=		sysutils
MASTER_SITES=		http://bughost.org/ipw3945/ucode/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bughost.org/ipw3945/
COMMENT=		Firmware binary images for wpi(4) driver

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	libdata/if_wpi

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.ipw3945-ucode ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/README.ipw3945-ucode ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/ipw3945.ucode ${DESTDIR}${PREFIX}/libdata/if_wpi

.include "../../mk/bsd.pkg.mk"
