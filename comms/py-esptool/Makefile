# $NetBSD: Makefile,v 1.6 2021/09/09 08:04:23 adam Exp $

DISTNAME=	esptool-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/esptool/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/espressif/esptool
COMMENT=	Firmware tool for ESP8266/ESP32
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-bitstring>=3.1.6:../../devel/py-bitstring
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.1.4:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.16.0:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-reedsolo>=1.5.3:../../converters/py-reedsolo
DEPENDS+=	${PYPKGPREFIX}-serial>=3.0:../../comms/py-serial

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
