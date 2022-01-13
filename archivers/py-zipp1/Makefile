# $NetBSD: Makefile,v 1.6 2022/01/13 19:31:20 wiz Exp $

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
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2
# not available for python 2.x
# https://github.com/jaraco/zipp/issues/49
#TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.itertools-[0-9]*:../../devel/py-jaraco.itertools
TEST_DEPENDS+=	${PYPKGPREFIX}-func_timeout-[0-9]*:../../devel/py-func_timeout

USE_LANGUAGES=	# none
PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
