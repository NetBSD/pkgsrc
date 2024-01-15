# $NetBSD: Makefile,v 1.13 2024/01/15 08:35:39 adam Exp $

DISTNAME=	python-memcached-1.62
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/1}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-memcached/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/linsomniac/python-memcached
COMMENT=	Python memcached client
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	memcache.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
