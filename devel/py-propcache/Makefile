# $NetBSD: Makefile,v 1.1 2024/10/10 06:35:58 wiz Exp $

DISTNAME=	propcache-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/propcache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/propcache
COMMENT=	Accelerated property cache
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-expandvars-[0-9]*:../../misc/py-expandvars
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults-[0-9]*:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	c

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
