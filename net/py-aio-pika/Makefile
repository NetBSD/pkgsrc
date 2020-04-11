# $NetBSD: Makefile,v 1.4 2020/04/11 07:40:34 adam Exp $

DISTNAME=	aio-pika-6.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aio-pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aio-pika.readthedocs.org/
COMMENT=	Wrapper for the aiormq for asyncio and humans
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiormq>=3.2.0:../../net/py-aiormq
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
