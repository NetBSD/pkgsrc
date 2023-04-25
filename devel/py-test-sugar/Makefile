# $NetBSD: Makefile,v 1.12 2023/04/25 14:03:38 wiz Exp $

DISTNAME=	pytest-sugar-0.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-sugar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pivotfinland.com/pytest-sugar/
COMMENT=	Py.test plugin that changes the default look and feel
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-termcolor>=2.1.0:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
