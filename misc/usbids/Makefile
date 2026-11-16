# $NetBSD: Makefile,v 1.8 2026/11/16 19:25:07 drixter Exp $
#

DISTNAME=	usbids-20260626
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=usbids/}
GITHUB_PROJECT=	usbids
GITHUB_TAG=	5eb613762db1e34b9218da63a88f22dd26f743c5

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	http://www.linux-usb.org/
COMMENT=	Repository of USB IDs (usb.ids database)
LICENSE=	modified-bsd OR gnu-gpl-v2

NO_BUILD=		yes

INSTALLATION_DIRS+=	share/usbids

do-install:
	${INSTALL_DATA} ${WRKDIR}/usbids-${GITHUB_TAG}/usb.ids ${DESTDIR}${PREFIX}/share/usbids

.include "../../mk/bsd.pkg.mk"
