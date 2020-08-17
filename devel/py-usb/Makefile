# $NetBSD: Makefile,v 1.21 2020/08/17 07:00:32 riastradh Exp $

VERSION=	1.0.2
DISTNAME=	pyusb-${VERSION}
PKGNAME=	${PYPKGPREFIX}-usb-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pyusb/}
GITHUB_PROJECT=	pyusb
GITHUB_TAG=	v${VERSION}

MAINTAINER=	wiml@hhhh.org
HOMEPAGE=	https://pyusb.github.io/pyusb/
COMMENT=	Python interface to USB via libusb
LICENSE=	modified-bsd

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

.include "../../mk/libusb.buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
