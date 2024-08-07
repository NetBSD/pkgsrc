# $NetBSD: Makefile,v 1.5 2024/08/07 10:48:07 adam Exp $

DISTNAME=	jaraco_vcs-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.vcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.vcs
COMMENT=	Facilities for working with VCS repositories
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/_/./:C/-([^0-9])/_\1/g}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jaraco.classes-[0-9]*:../../devel/py-jaraco.classes
DEPENDS+=	${PYPKGPREFIX}-jaraco.path-[0-9]*:../../devel/py-jaraco.path
DEPENDS+=	${PYPKGPREFIX}-jaraco.versioning-[0-9]*:../../devel/py-jaraco.versioning
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-tempora-[0-9]*:../../time/py-tempora
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
