# $NetBSD: Makefile,v 1.2 2008/09/08 13:37:33 joerg Exp $
#

DISTNAME=		ipw3945-ucode-1.13
PKGNAME=		wpi-firmware-1.13
CATEGORIES=		sysutils
MASTER_SITES=		http://bughost.org/ipw3945/ucode/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bughost.org/ipw3945/
COMMENT=		Firmware binary images for wpi(4) driver

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	libdata/if_wpi

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.ipw3945-ucode ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/README.ipw3945-ucode ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/ipw3945.ucode ${DESTDIR}${PREFIX}/libdata/if_wpi

.include "../../mk/bsd.pkg.mk"
