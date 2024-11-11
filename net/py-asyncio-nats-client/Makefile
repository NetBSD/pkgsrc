# $NetBSD: Makefile,v 1.4 2024/11/11 07:28:46 wiz Exp $

DISTNAME=	asyncio-nats-client-0.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncio-nats-client/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/nats-io/nats.py
COMMENT=	NATS client for Python asyncio
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
