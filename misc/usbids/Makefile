# $NetBSD: Makefile,v 1.1.1.1 2008/11/22 13:06:40 jmcneill Exp $
#

DISTNAME=	usbids-20081118
CATEGORIES=	misc
MASTER_SITES=	http://www.invisible.ca/~jmcneill/distfiles/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://www.linux-usb.org/
COMMENT=	Repository of USB IDs (usb.ids database)

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/usbids
	${INSTALL_DATA} ${WRKSRC}/usb.ids ${DESTDIR}${PREFIX}/share/usbids

.include "../../mk/bsd.pkg.mk"
