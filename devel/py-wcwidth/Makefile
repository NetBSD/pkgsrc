# $NetBSD: Makefile,v 1.17 2024/01/06 09:42:55 adam Exp $

DISTNAME=	wcwidth-0.2.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wcwidth/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jquast/wcwidth
COMMENT=	Measures number of Terminal column cells of wide-character codes
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache>=1.2.1:../../devel/py-backports.functools_lru_cache
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
