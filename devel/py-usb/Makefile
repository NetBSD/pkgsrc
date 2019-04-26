# $NetBSD: Makefile,v 1.18 2019/04/26 13:13:54 maya Exp $

VERSION=	1.0.0
PKGREVISION=	1
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

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.4.2

.include "../../mk/libusb.buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
