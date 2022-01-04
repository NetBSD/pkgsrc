# $NetBSD: Makefile,v 1.52 2022/01/04 20:52:55 wiz Exp $

DISTNAME=	cffi-1.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cffi.readthedocs.io/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_LANGUAGES=	c c++ # c++ for testing only
USE_TOOLS+=	pkg-config

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

PYTHON_VERSIONED_DEPENDENCIES=	test:test

DISTUTILS_BUILDDIR_IN_TEST_ENV=	yes

# to avoid py-hypothesis
TEST_ENV+=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1
TEST_ENV+=	TMPDIR=${WRKDIR}/tmp

do-test:
	${MKDIR} ${WRKDIR}/tmp
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} testing

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
