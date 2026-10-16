# $NetBSD: Makefile,v 1.26 2026/10/16 19:44:07 adam Exp $

DISTNAME=	aio_pika-10.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aio-pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aio-pika
COMMENT=	Wrapper for the aiormq for asyncio and humans
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.26:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-aiormq>=7.1.3:../../net/py-aiormq
DEPENDS+=	${PYPKGPREFIX}-yarl>=0:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-aiormq

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
