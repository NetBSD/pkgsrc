# $NetBSD: Makefile,v 1.32 2026/10/18 14:26:35 wiz Exp $

DISTNAME=	pluggy-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pluggy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pluggy
COMMENT=	Plugin and hook calling mechanisms for python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2.3:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

# as of 1.7.0
# 68 failed, 151 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
