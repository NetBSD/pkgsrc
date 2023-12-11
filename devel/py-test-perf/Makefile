# $NetBSD: Makefile,v 1.1 2023/12/11 09:51:33 wiz Exp $

DISTNAME=	pytest-perf-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-perf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/pytest-perf
COMMENT=	Run performance tests against the mainline code
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pip-run>=8.5:../../devel/py-pip-run
DEPENDS+=	${PYPKGPREFIX}-tempora>=4.1:../../time/py-tempora
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=0:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-jaraco.context>=0:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
# assumes git checkout, not pypi distfile
#TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
