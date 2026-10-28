# $NetBSD: Makefile,v 1.7 2026/10/28 20:06:02 drixter Exp $
#

DISTNAME=	usbids-20260626
CATEGORIES=	misc
MASTER_SITES=	http://www.linux-usb.org/
DIST_SUBDIR=	usbids-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.gz
DISTFILES=	usb.ids.gz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	http://www.linux-usb.org/
COMMENT=	Repository of USB IDs (usb.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

NO_BUILD=		yes

INSTALLATION_DIRS+=	share/usbids

do-install:
	${INSTALL_DATA} ${WRKDIR}/usb.ids ${DESTDIR}${PREFIX}/share/usbids


.include "../../mk/bsd.pkg.mk"
