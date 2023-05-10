# $NetBSD: Makefile,v 1.7 2023/05/10 20:15:10 nikita Exp $

GITHUB_PROJECT=	hidapi
GITHUB_TAG=	${GITHUB_PROJECT}-0.13.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	lib${DISTNAME}
CATEGORIES=	comms devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}

MAINTAINER=	nathanialsloss@yahoo.com.au
HOMEPAGE=	https://github.com/libusb/hidapi
COMMENT=	Library for comunicating with bluetooth and usb hid devices
LICENSE=	gnu-gpl-v3 OR modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

LDFLAGS+=		-lpthread

PKGCONFIG_OVERRIDE+=	pc/hidapi-hidraw.pc.in
PKGCONFIG_OVERRIDE+=	pc/hidapi-libusb.pc.in
PKGCONFIG_OVERRIDE+=	pc/hidapi.pc.in

PLIST_VARS+=	libusb

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PLIST.libusb=	yes
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
