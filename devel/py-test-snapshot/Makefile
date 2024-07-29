# $NetBSD: Makefile,v 1.2 2024/07/29 07:08:45 wiz Exp $

DISTNAME=	pytest-snapshot-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-snapshot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joseph-roitman/pytest-snapshot
COMMENT=	Plugin for snapshot testing with pytest
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# 5 failed, 102 passed, 1 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
