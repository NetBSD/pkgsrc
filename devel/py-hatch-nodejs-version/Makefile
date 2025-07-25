# $NetBSD: Makefile,v 1.4 2025/07/25 11:15:43 adam Exp $

DISTNAME=	hatch_nodejs_version-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-nodejs-version/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agoose77/hatch-nodejs-version
COMMENT=	Hatch plugin for versioning from a package.json file
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=0.21.0:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0.1:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
