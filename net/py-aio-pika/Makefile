# $NetBSD: Makefile,v 1.8 2022/01/04 20:54:24 wiz Exp $

DISTNAME=	aio-pika-6.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aio-pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aio-pika.readthedocs.io/
COMMENT=	Wrapper for the aiormq for asyncio and humans
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiormq>=3.2.3:../../net/py-aiormq
DEPENDS+=	${PYPKGPREFIX}-yarl-[0-9]*:../../www/py-yarl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
