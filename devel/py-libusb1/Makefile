# $NetBSD: Makefile,v 1.4 2023/05/18 09:56:50 nikita Exp $

DISTNAME=	libusb1-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libusb1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vpelletier/python-libusb1
COMMENT=	Python ctype-based wrapper around libusb1
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

# dropped support for < 3.6 in version 3.0
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
