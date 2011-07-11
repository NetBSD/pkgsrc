# $NetBSD: Makefile,v 1.1.1.1 2011/07/11 18:26:29 jmcneill Exp $
#

DISTNAME=		xc3028L-v36.fw
PKGNAME=		xc3028l-firmware-3.6
CATEGORIES=		sysutils
MASTER_SITES=		http://steventoth.net/linux/hvr1400/
EXTRACT_SUFX=		# none

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Firmware binary image for Xceive XC3028L tuners

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	libdata/firmware/xc3028

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
	    ${DESTDIR}${PREFIX}/libdata/firmware/xc3028

.include "../../mk/bsd.pkg.mk"
