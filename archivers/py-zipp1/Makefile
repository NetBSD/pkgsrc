# $NetBSD: Makefile,v 1.9 2023/06/06 12:40:15 riastradh Exp $

DISTNAME=	zipp-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zipp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/zipp
COMMENT=	Backport of pathlib-compatible object wrapper for zip files (for Python 2.x)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm5
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
# not available for python 2.x
# https://github.com/jaraco/zipp/issues/49
#TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.itertools-[0-9]*:../../devel/py-jaraco.itertools
# removed from pkgsrc
#TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2
TEST_DEPENDS+=	${PYPKGPREFIX}-func_timeout-[0-9]*:../../devel/py-func_timeout

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED= 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
