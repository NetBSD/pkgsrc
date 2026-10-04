# $NetBSD: Makefile,v 1.28 2026/10/04 16:51:29 wiz Exp $

DISTNAME=	pdm_backend-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdm-backend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pdm-project/pdm-backend
COMMENT=	Build backend used by PDM that supports latest packaging standards
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-editables-[0-9]*:../../devel/py-editables
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial

USE_LANGUAGES=	c # for tests
USE_TOOLS+=	git:test

# as of 2.5.0
# 95 passed, 1 skipped
pre-test:
	${SETENV} ${TEST_ENV} git config set --global user.name Test
	${SETENV} ${TEST_ENV} git config set --global user.email Test

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
