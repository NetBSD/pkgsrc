# $NetBSD: Makefile,v 1.44 2026/09/10 11:21:25 adam Exp $

DISTNAME=	multidict-6.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multidict/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/multidict
COMMENT=	Multidict implementation
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-objgraph>=3.6.2:../../graphics/py-objgraph
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=7.2.2:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-codspeed>=5.0.3:../../devel/py-test-codspeed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1.0:../../devel/py-test-cov

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
