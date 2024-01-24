# $NetBSD: Makefile,v 1.7 2024/01/24 06:52:31 adam Exp $

DISTNAME=	toolz-0.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toolz/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pytoolz/toolz
COMMENT=	List processing tools and functional utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
