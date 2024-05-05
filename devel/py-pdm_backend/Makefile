# $NetBSD: Makefile,v 1.13 2024/05/05 16:30:09 wiz Exp $

DISTNAME=	pdm_backend-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdm-backend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pdm-project/pdm-backend
COMMENT=	Build backend used by PDM that supports latest packaging standards
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-editables-[0-9]*:../../devel/py-editables
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

USE_LANGUAGES=	c # for tests

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
