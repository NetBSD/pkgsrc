# $NetBSD: Makefile,v 1.13 2022/07/08 13:24:51 gdt Exp $

DISTNAME=	esptool-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/esptool/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/espressif/esptool
COMMENT=	Firmware tool for ESP8266/ESP32
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-bitstring>=3.1.6:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.16.0:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-reedsolo>=1.5.3:../../converters/py-reedsolo
DEPENDS+=	${PYPKGPREFIX}-serial>=3.0:../../comms/py-serial

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
