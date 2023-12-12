# $NetBSD: Makefile,v 1.8 2023/12/12 16:48:58 adam Exp $

DISTNAME=	distlib-0.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/distlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/distlib
COMMENT=	Distribution utilities
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=44:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.29.0:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
