# $NetBSD: Makefile,v 1.1 2022/09/15 17:51:07 adam Exp $

DISTNAME=	blessed-1.19.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blessed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jquast/blessed
COMMENT=	Wrapper around terminal styling, screen positioning, and input
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.4:../../devel/py-wcwidth

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache-[0-9]*:../../devel/py-backports.functools_lru_cache
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
