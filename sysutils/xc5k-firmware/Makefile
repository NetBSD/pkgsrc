# $NetBSD: Makefile,v 1.1.1.1 2010/12/27 16:28:45 jmcneill Exp $
#

DISTNAME=		dvb-fe-xc5000-1.6.114.fw
PKGNAME=		xc5k-firmware-1.6.114
CATEGORIES=		sysutils
MASTER_SITES=		http://www.linuxtv.org/downloads/firmware/
EXTRACT_SUFX=		# none

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.linuxtv.org/
COMMENT=		Firmware binary image for Xceive XC5000 tuners

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	libdata/firmware/xc5k

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
	    ${DESTDIR}${PREFIX}/libdata/firmware/xc5k

.include "../../mk/bsd.pkg.mk"
