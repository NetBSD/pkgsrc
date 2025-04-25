# $NetBSD: Makefile,v 1.7 2025/04/25 11:06:53 wiz Exp $

DISTNAME=	volatility3-2.7.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=volatilityfoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.volatilityfoundation.org/
COMMENT=	Advanced memory forensics framework
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pefile>=2023.2.7:../../sysutils/py-pefile
# Optional; see requirements.txt
DEPENDS+=	${PYPKGPREFIX}-capstone>=3.0.5:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-snappy>=0.6.0:../../devel/py-snappy
DEPENDS+=	${PYPKGPREFIX}-yara>=3.8.0:../../security/py-yara
# Missing: leechcorepyc>=2.4.0

USE_LANGUAGES=	# none

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
