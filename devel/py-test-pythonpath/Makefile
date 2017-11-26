# $NetBSD: Makefile,v 1.1 2017/11/26 17:11:15 adam Exp $

DISTNAME=	pytest-pythonpath-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-pythonpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bigsassy/pytest-pythonpath
COMMENT=	Pytest plugin for adding to the PYTHONPATH
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.5.2:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
