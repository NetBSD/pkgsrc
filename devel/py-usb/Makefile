# $NetBSD: Makefile,v 1.14 2017/12/24 10:13:22 wiz Exp $

VERSION=	1.0.0
DISTNAME=	pyusb-${VERSION}
PKGNAME=	${PYPKGPREFIX}-usb-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pyusb/}
GITHUB_PROJECT=	pyusb

MAINTAINER=	wiml@hhhh.org
HOMEPAGE=	https://pyusb.github.io/pyusb/
COMMENT=	Python interface to USB via libusb
LICENSE=	modified-bsd

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.4.2

.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
