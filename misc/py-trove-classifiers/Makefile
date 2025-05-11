# $NetBSD: Makefile,v 1.39 2025/05/11 10:34:57 wiz Exp $

DISTNAME=	trove_classifiers-2025.5.9.12
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

# as of 2025.5.9.12
# 3 failed, 15 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
