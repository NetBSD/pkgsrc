# $NetBSD: Makefile,v 1.3 2026/11/24 22:33:12 wiz Exp $

DISTNAME=	httpx2_kerberos-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx2-kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/achapkowski/httpx2_kerberos
COMMENT=	Kerberos authentication for HTTPX2
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=46.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-httpx2>=2.2.0:../../www/py-httpx2
DEPENDS+=	${PYPKGPREFIX}-pyspnego>=0.12.1:../../security/py-pyspnego

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-pyspnego

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
