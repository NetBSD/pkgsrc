# $NetBSD: Makefile,v 1.6 2020/07/29 12:07:15 adam Exp $

DISTNAME=	lazy-object-proxy-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy-object-proxy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ionelmc/python-lazy-object-proxy
COMMENT=	Fast and thorough lazy object proxy
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3.0:../../devel/py-setuptools
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.3.1:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
