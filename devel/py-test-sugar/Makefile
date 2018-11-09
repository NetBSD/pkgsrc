# $NetBSD: Makefile,v 1.4 2018/11/09 10:48:20 adam Exp $

DISTNAME=	pytest-sugar-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-sugar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pivotfinland.com/pytest-sugar/
COMMENT=	Py.test plugin that changes the default look and feel
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-termcolor>=1.1.0:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-test>=2.9:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
