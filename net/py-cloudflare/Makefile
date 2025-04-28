# $NetBSD: Makefile,v 1.4 2025/04/28 09:01:48 adam Exp $

DISTNAME=	cloudflare-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cloudflare/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cloudflare/python-cloudflare
COMMENT=	Python wrapper for the Cloudflare v4 API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.26.3:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-anyio>=3.5.0:../../devel/py-anyio
DEPENDS+=	${PYPKGPREFIX}-distro>=1.7.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.23.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-pydantic>=1.9.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-sniffio>0:../../misc/py-sniffio
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.10:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-respx>0:../../www/py-respx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
