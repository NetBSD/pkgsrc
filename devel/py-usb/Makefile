# $NetBSD: Makefile,v 1.10 2016/07/09 13:03:44 wiz Exp $

VERSION=	0.4.2
DISTNAME=	pyusb-${VERSION}
PKGNAME=	${PYPKGPREFIX}-usb-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyusb/}

MAINTAINER=	wiml@hhhh.org
HOMEPAGE=	http://pyusb.berlios.de/
COMMENT=	Python interface to USB via libusb

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.4.2

.include "../../devel/libusb/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
