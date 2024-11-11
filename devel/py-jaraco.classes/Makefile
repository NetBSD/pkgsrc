# $NetBSD: Makefile,v 1.12 2024/11/11 07:28:12 wiz Exp $

DISTNAME=	jaraco.classes-3.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.classes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.classes
COMMENT=	Utility functions for Python class constructs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
