# $NetBSD: Makefile,v 1.20 2025/08/26 10:46:18 adam Exp $

DISTNAME=	lazy_object_proxy-1.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy-object-proxy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ionelmc/python-lazy-object-proxy
COMMENT=	Fast and thorough lazy object proxy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
