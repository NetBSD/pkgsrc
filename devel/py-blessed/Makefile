# $NetBSD: Makefile,v 1.3 2023/05/13 08:26:01 adam Exp $

DISTNAME=	blessed-1.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blessed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jquast/blessed
COMMENT=	Wrapper around terminal styling, screen positioning, and input
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.4:../../devel/py-wcwidth

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache>=1.2.1:../../devel/py-backports.functools_lru_cache
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
