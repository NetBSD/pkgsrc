# $NetBSD: Makefile,v 1.5 2017/09/06 10:40:33 wiz Exp $

DISTNAME=		ipw3945-ucode-1.14.2
PKGNAME=		wpi-firmware-1.14.2
CATEGORIES=		sysutils
#MASTER_SITES=		http://web.archive.org/web/20101115131002/http://bughost.org/ipw3945/ucode/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://bughost.org/ipw3945/
COMMENT=		Firmware binary images for wpi(4) driver
#LICENSE=		see work/ipw3945-ucode-1.14.2/LICENSE.ipw3945-ucode

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	libdata/if_wpi

do-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE.ipw3945-ucode ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/README.ipw3945-ucode ${DESTDIR}${PREFIX}/libdata/if_wpi
	${INSTALL_DATA} ${WRKSRC}/ipw3945.ucode ${DESTDIR}${PREFIX}/libdata/if_wpi

.include "../../mk/bsd.pkg.mk"
