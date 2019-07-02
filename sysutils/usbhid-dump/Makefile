# $NetBSD: Makefile,v 1.1 2019/07/02 13:29:33 ryoon Exp $

DISTNAME=	usbhid-dump-1.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=DIGImend/}
GITHUB_RELEASE=	1.4

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/DIGImend/usbhid-dump/
COMMENT=	USB HID device dumping utility
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
