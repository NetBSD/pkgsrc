# $NetBSD: Makefile,v 1.14 2024/11/11 07:28:27 wiz Exp $

DISTNAME=	pytest-sugar-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-sugar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pivotfinland.com/pytest-sugar/
COMMENT=	Py.test plugin that changes the default look and feel
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.6.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-termcolor>=2.1.0:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
