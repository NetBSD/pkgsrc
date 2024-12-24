# $NetBSD: Makefile,v 1.16 2024/12/24 18:54:42 adam Exp $

DISTNAME=	aio_pika-9.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aio-pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mosquito/aio-pika
COMMENT=	Wrapper for the aiormq for asyncio and humans
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-aiormq>=6.8.0:../../net/py-aiormq
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1:../../devel/py-exceptiongroup
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
