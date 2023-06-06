# $NetBSD: Makefile,v 1.24 2023/06/06 12:41:15 riastradh Exp $

DISTNAME=	pyusb-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyusb/usb/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyusb/}

MAINTAINER=	wiml@hhhh.org
HOMEPAGE=	https://pyusb.github.io/pyusb/
COMMENT=	Python interface to USB via libusb
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/libusb.buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
