# $NetBSD: Makefile,v 1.10 2026/05/10 13:55:19 wiz Exp $

DISTNAME=	propcache-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/propcache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/propcache
COMMENT=	Accelerated property cache
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-expandvars-[0-9]*:../../misc/py-expandvars
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults-[0-9]*:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-codspeed>=3.0.0:../../devel/py-test-codspeed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.3.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
