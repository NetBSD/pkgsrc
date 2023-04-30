# $NetBSD: Makefile,v 1.12 2023/04/30 15:12:37 wiz Exp $

DISTNAME=	blinker-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blinker/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://blinker.readthedocs.io/
COMMENT=	Fast, simple object-to-object and broadcast signaling
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
