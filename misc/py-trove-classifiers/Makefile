# $NetBSD: Makefile,v 1.22 2024/05/20 09:56:57 adam Exp $

DISTNAME=	trove_classifiers-2024.5.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trove-classifiers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/trove-classifiers
COMMENT=	Canonical source for classifiers on PyPI (pypi.org)
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-calver-[0-9]*:../../devel/py-calver
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
