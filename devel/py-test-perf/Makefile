# $NetBSD: Makefile,v 1.3 2025/04/12 21:10:57 adam Exp $

DISTNAME=	pytest-perf-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-perf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/pytest-perf
COMMENT=	Run performance tests against the mainline code
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-pip-run>=8.5:../../devel/py-pip-run
DEPENDS+=	${PYPKGPREFIX}-tempora>=4.1:../../time/py-tempora
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=0:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-jaraco.context>=0:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
# assumes git checkout, not pypi distfile
#TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
