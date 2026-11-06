# $NetBSD: Makefile,v 1.14 2026/11/06 14:12:53 adam Exp $

DISTNAME=	hidapi-0.15.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	comms devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}
GITHUB_PROJECT=	hidapi
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	nathanialsloss@yahoo.com.au
HOMEPAGE=	https://github.com/libusb/hidapi
COMMENT=	Library for comunicating with bluetooth and usb hid devices
LICENSE=	gnu-gpl-v3 OR modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PTHREAD_AUTO_VARS=	yes
LDFLAGS+=		${PTHREAD_LFLAGS}

PKGCONFIG_OVERRIDE+=	pc/hidapi-hidraw.pc.in
PKGCONFIG_OVERRIDE+=	pc/hidapi-libusb.pc.in
PKGCONFIG_OVERRIDE+=	pc/hidapi.pc.in

PLIST_VARS+=	libusb hidraw netbsd
PLIST_SUBST+=	PKGVERSION=${PKGVERSION_NOREV}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PLIST.libusb=	yes
.  if ${OPSYS} == "Linux"
PLIST.hidraw=	yes
.  elif ${OPSYS} == "NetBSD"
PLIST.netbsd=	yes
.  endif
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
