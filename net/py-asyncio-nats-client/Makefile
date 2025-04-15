# $NetBSD: Makefile,v 1.5 2025/04/15 05:38:02 adam Exp $

DISTNAME=	asyncio-nats-client-0.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asyncio-nats-client/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/nats-io/nats.py
COMMENT=	NATS client for Python asyncio
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
