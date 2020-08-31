# $NetBSD: Makefile,v 1.7 2020/08/31 23:07:01 wiz Exp $

DISTNAME=	lazy-object-proxy-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy-object-proxy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ionelmc/python-lazy-object-proxy
COMMENT=	Fast and thorough lazy object proxy
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.3.1:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools:build

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
