# $NetBSD: Makefile,v 1.11 2022/01/13 19:31:21 wiz Exp $

DISTNAME=	execnet-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/execnet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://execnet.readthedocs.io/
COMMENT=	Rapid multi-Python deployment
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} testing

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
