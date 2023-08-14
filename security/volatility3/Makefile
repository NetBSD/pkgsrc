# $NetBSD: Makefile,v 1.2 2023/08/14 05:25:12 wiz Exp $

DISTNAME=	volatility3-2.0.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=volatilityfoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.volatilityfoundation.org/
COMMENT=	Advanced memory forensics framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pefile>=2017.8.1:../../sysutils/py-pefile
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
# Optional; see requirements.txt
DEPENDS+=	${PYPKGPREFIX}-capstone>=3.0.5:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-snappy>=0.6.0:../../devel/py-snappy
DEPENDS+=	${PYPKGPREFIX}-yara>=3.8.0:../../security/py-yara
# Missing: leechcorepyc>=2.4.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
