# $NetBSD: Makefile,v 1.4 2024/06/11 10:39:50 adam Exp $

DISTNAME=	volatility3-2.7.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=volatilityfoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.volatilityfoundation.org/
COMMENT=	Advanced memory forensics framework
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pefile>=2023.2.7:../../sysutils/py-pefile
# Optional; see requirements.txt
DEPENDS+=	${PYPKGPREFIX}-capstone>=3.0.5:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-snappy>=0.6.0:../../devel/py-snappy
DEPENDS+=	${PYPKGPREFIX}-yara>=3.8.0:../../security/py-yara
# Missing: leechcorepyc>=2.4.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
