# $NetBSD: Makefile,v 1.1 2026/03/31 13:57:50 khorben Exp $

DISTNAME=	usbboot-1.0
PKGNAME=	raspberrypi-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=raspberrypi/}
GITHUB_PROJECT=	usbboot
GITHUB_TAG=	windows-v1.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/raspberrypi/usbboot
COMMENT=	Raspberry Pi USB device boot
LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config

BUILD_DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share
BUILD_TARGET=	rpiboot

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	INSTALL_PREFIX=${PREFIX}
MAKE_FLAGS+=	GIT_VER=${GITHUB_TAG}
MAKE_FLAGS+=	PKG_VER=${PKGVERSION}
AUTO_MKDIRS=	yes

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
