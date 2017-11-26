# $NetBSD: Makefile,v 1.3 2017/11/26 16:56:06 adam Exp $

DISTNAME=	pytest-timeout-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-timeout/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/pytest-dev/pytest-timeout/
COMMENT=	Py.test plugin to abort hanging tests
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.8.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
