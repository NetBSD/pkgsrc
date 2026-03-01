# $NetBSD: Makefile,v 1.2 2026/03/01 07:11:19 wiz Exp $

DISTNAME=	noiseprotocol-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/noiseprotocol/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/plizonczyk/noiseprotocol
COMMENT=	Python 3 implementation of Noise Protocol Framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
