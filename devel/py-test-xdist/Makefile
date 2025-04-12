# $NetBSD: Makefile,v 1.45 2025/04/12 21:10:59 adam Exp $

DISTNAME=	pytest_xdist-3.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-xdist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-xdist
COMMENT=	Plugin for distributed testing and loop-on-failing modes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2.3:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-execnet>=2.1:../../devel/py-execnet
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
