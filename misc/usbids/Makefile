# $NetBSD: Makefile,v 1.3 2012/03/13 03:13:48 taca Exp $
#

DISTNAME=	usbids-20081118
CATEGORIES=	misc
MASTER_SITES=	http://www.invisible.ca/~jmcneill/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linux-usb.org/
COMMENT=	Repository of USB IDs (usb.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/usbids
	${INSTALL_DATA} ${WRKSRC}/usb.ids ${DESTDIR}${PREFIX}/share/usbids

.include "../../mk/bsd.pkg.mk"
