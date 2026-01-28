# $NetBSD: Makefile,v 1.18 2026/01/28 10:37:20 wiz Exp $

DISTNAME=	pytest-sugar-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-sugar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Teemu/pytest-sugar
COMMENT=	Py.test plugin that changes the default look and feel
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-termcolor>=2.1.0:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
