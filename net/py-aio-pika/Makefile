# $NetBSD: Makefile,v 1.10 2024/03/24 19:15:55 adam Exp $

DISTNAME=	aio_pika-9.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aio-pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aio-pika
COMMENT=	Wrapper for the aiormq for asyncio and humans
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-aiormq>=6.8.0:../../net/py-aiormq
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
