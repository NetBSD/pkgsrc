# $NetBSD: Makefile,v 1.15 2026/05/11 16:09:17 adam Exp $

DISTNAME=	python_subunit-1.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-subunit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/subunit
COMMENT=	Python implementation of subunit test streaming protocol
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-iso8601-[0-9]*:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-testtools>=2.7:../../devel/py-testtools
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios

USE_LANGUAGES=	# none

PY_RENAME_BINARIES+=	gojson2subunit junitxml2subunit subunit-1to2
PY_RENAME_BINARIES+=	subunit-2to1 subunit-combine subunit-filter
PY_RENAME_BINARIES+=	subunit-ls subunit-notify subunit-output subunit-stats
PY_RENAME_BINARIES+=	subunit-tags subunit2csv subunit2disk subunit2gtk
PY_RENAME_BINARIES+=	subunit2junitxml subunit2pyunit tap2subunit

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
