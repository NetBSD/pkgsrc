# $NetBSD: Makefile,v 1.2 2026/02/12 11:09:59 adam Exp $

DISTNAME=	pytest_html-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-html/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-html
COMMENT=	Pytest plugin for generating HTML reports
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.13:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-metadata>=2:../../devel/py-test-metadata
TEST_DEPENDS+=	${PYPKGPREFIX}-assertpy>=1.1:../../devel/py-assertpy
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.11.1:../../www/py-beautifulsoup4
# TODO: selenium>=4.3
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.7:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=11.1.2:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
