# $NetBSD: Makefile,v 1.20 2025/09/30 14:25:32 wiz Exp $

DISTNAME=	aio_pika-9.5.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aio-pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aio-pika
COMMENT=	Wrapper for the aiormq for asyncio and humans
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-aiormq>=6.8.0:../../net/py-aiormq
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-aiormq

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
