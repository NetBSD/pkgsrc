# $NetBSD: Makefile,v 1.4 2012/10/08 09:57:39 asau Exp $
#

DISTNAME=	usbids-20081118
CATEGORIES=	misc
MASTER_SITES=	http://www.invisible.ca/~jmcneill/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linux-usb.org/
COMMENT=	Repository of USB IDs (usb.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

NO_BUILD=		yes

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/usbids
	${INSTALL_DATA} ${WRKSRC}/usb.ids ${DESTDIR}${PREFIX}/share/usbids

.include "../../mk/bsd.pkg.mk"
