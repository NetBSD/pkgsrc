# $NetBSD: Makefile,v 1.1 2025/01/29 09:23:44 adam Exp $

DISTNAME=	pytest_html-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-html/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-html
COMMENT=	Pytest plugin for generating HTML reports
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.13:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-test-metadata>=2.0.0:../../devel/py-test-metadata
# TODO: assertpy>=1.1
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.11.1:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.7.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=11.1.2:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.4.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
