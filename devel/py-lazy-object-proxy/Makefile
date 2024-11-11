# $NetBSD: Makefile,v 1.17 2024/11/11 07:28:14 wiz Exp $

DISTNAME=	lazy-object-proxy-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy-object-proxy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ionelmc/python-lazy-object-proxy
COMMENT=	Fast and thorough lazy object proxy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
