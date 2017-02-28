# $NetBSD: Makefile,v 1.1 2017/02/28 20:47:57 fhajny Exp $

DISTNAME=	backports.functools_lru_cache-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.functools_lru_cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/backports.functools_lru_cache/
COMMENT=	Backport of functools.lru_cache from Python 3.3
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
