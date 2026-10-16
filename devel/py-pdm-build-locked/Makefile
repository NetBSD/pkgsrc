# $NetBSD: Makefile,v 1.5 2026/10/16 17:55:56 adam Exp $

DISTNAME=	pdm_build_locked-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdm-build-locked/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pdm-project/pdm-build-locked
COMMENT=	Pdm plugin to add locked packages as optional dependency groups
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=0:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.9.6:../../devel/py-pkginfo
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
