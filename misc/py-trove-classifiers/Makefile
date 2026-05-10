# $NetBSD: Makefile,v 1.49 2026/05/10 13:59:39 wiz Exp $

DISTNAME=	trove_classifiers-2026.5.7.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trove-classifiers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/trove-classifiers
COMMENT=	Canonical source for classifiers on PyPI (pypi.org)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-calver-[0-9]*:../../devel/py-calver
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	trove-classifiers

SUBST_CLASSES+=		test
SUBST_FILES.test+=	tests/test_cli.py
SUBST_SED.test+=	-e "s,trove-classifiers,trove-classifiers-${PYVERSSUFFIX},"
SUBST_MESSAGE.test=	Fixing binary name.
SUBST_STAGE.test=	pre-test

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
