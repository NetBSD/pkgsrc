# $NetBSD: Makefile,v 1.19 2024/03/06 18:57:48 adam Exp $

DISTNAME=	trove-classifiers-2024.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
