# $NetBSD: Makefile,v 1.25 2026/04/05 11:43:27 wiz Exp $

DISTNAME=	pdm_backend-2.4.8
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

# as of 2.4.8
# 73 passed, 1 skipped, 21 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
