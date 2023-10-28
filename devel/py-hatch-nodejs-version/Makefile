# $NetBSD: Makefile,v 1.3 2023/10/28 19:57:01 wiz Exp $

DISTNAME=	hatch_nodejs_version-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-nodejs-version/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agoose77/hatch-nodejs-version
COMMENT=	Hatch plugin for versioning from a package.json file
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.21.0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0.1:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
