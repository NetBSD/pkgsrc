# $NetBSD: Makefile,v 1.7 2023/11/05 00:43:09 wiz Exp $

DISTNAME=	pyhamcrest-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^pyh/h/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyHamcrest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hamcrest/PyHamcrest
COMMENT=	Framework for writing matcher objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
