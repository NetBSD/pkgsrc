# $NetBSD: Makefile,v 1.25 2025/01/03 10:13:58 adam Exp $

DISTNAME=	pyusb-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyusb/}

MAINTAINER=	wiml@hhhh.org
HOMEPAGE=	https://pyusb.github.io/pyusb/
COMMENT=	Python interface to USB via libusb
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

.include "../../mk/libusb.buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
