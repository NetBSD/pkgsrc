# $NetBSD: Makefile,v 1.15 2024/01/30 23:47:13 adam Exp $

DISTNAME=	esptool-4.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/esptool/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/espressif/esptool
COMMENT=	Firmware tool for ESP8266/ESP32
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-bitstring>=3.1.6:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.16.0:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-intelhex-[0-9]*:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-reedsolo>=1.5.3:../../converters/py-reedsolo
DEPENDS+=	${PYPKGPREFIX}-serial>=3.0:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
