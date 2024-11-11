# $NetBSD: Makefile,v 1.7 2024/11/11 07:28:14 wiz Exp $

DISTNAME=	libusb1-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libusb1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vpelletier/python-libusb1
COMMENT=	Python ctype-based wrapper around libusb1
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
