# $NetBSD: Makefile,v 1.1 2020/03/12 06:59:22 wiz Exp $

DISTNAME=	zipp-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zipp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/zipp
COMMENT=	Backport of pathlib-compatible object wrapper for zip files (for Python 2.x)
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	more-itertools

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
