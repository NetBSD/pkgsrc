# $NetBSD: Makefile,v 1.48 2026/04/30 09:30:47 adam Exp $

DISTNAME=	trove_classifiers-2026.4.28.13
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

# as of 2025.11.14.15
# 2 failed, 16 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
