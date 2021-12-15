# $NetBSD: Makefile,v 1.10 2021/12/15 09:37:36 adam Exp $

DISTNAME=	lazy-object-proxy-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy-object-proxy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ionelmc/python-lazy-object-proxy
COMMENT=	Fast and thorough lazy object proxy
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.3.1:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
