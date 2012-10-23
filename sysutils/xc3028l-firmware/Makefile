# $NetBSD: Makefile,v 1.2 2012/10/23 19:51:35 asau Exp $
#

DISTNAME=		xc3028L-v36.fw
PKGNAME=		xc3028l-firmware-3.6
CATEGORIES=		sysutils
MASTER_SITES=		http://steventoth.net/linux/hvr1400/
EXTRACT_SUFX=		# none

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Firmware binary image for Xceive XC3028L tuners

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	libdata/firmware/xc3028

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
	    ${DESTDIR}${PREFIX}/libdata/firmware/xc3028

.include "../../mk/bsd.pkg.mk"
