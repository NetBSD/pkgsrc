# $NetBSD: Makefile,v 1.22 2025/12/15 11:07:49 triaxx Exp $

DISTNAME=	esptool-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/esptool/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/espressif/esptool
COMMENT=	Firmware tool for ESP8266/ESP32
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-bitstring>=4.2.1:../../devel/py-bitstring
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
DEPENDS+=	${PYPKGPREFIX}-serial>=3.3:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-reedsolo>=1.5.3:../../converters/py-reedsolo
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-intelhex-[0-9]*:../../devel/py-intelhex
DEPENDS+=	${PYPKGPREFIX}-rich-click-[0-9]*:../../devel/py-rich-click
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
