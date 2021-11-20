# $NetBSD: Makefile,v 1.4 2021/11/20 18:59:05 nia Exp $

GITHUB_PROJECT=	hidapi
GITHUB_TAG=	${GITHUB_PROJECT}-0.11.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	lib${DISTNAME}
CATEGORIES=	comms devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libusb/}

MAINTAINER=	nathanialsloss@yahoo.com.au
HOMEPAGE=	https://github.com/libusb/hidapi
COMMENT=	Library for comunicating with bluetooth and usb hid devices
LICENSE=	gnu-gpl-v3 OR modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config gmake

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	pc/hidapi-hidraw.pc.in
PKGCONFIG_OVERRIDE+=	pc/hidapi-libusb.pc.in
PKGCONFIG_OVERRIDE+=	pc/hidapi.pc.in

pre-configure:
	cd ${WRKSRC} && ${SH} ./bootstrap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
