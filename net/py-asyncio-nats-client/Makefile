# $NetBSD: Makefile,v 1.1 2020/01/08 17:06:50 minskim Exp $

DISTNAME=	asyncio-nats-client-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncio-nats-client/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/nats-io/nats.py
COMMENT=	NATS client for Python asyncio
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
