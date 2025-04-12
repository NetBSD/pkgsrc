# $NetBSD: Makefile,v 1.15 2025/04/12 21:10:59 adam Exp $

DISTNAME=	pytest-sugar-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-sugar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pivotfinland.com/pytest-sugar/
COMMENT=	Py.test plugin that changes the default look and feel
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-termcolor>=2.1.0:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
