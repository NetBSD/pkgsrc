# $NetBSD: Makefile,v 1.6 2022/01/13 19:31:23 wiz Exp $

DISTNAME=	jaraco.functools-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.functools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.functools
COMMENT=	Additional functools in the spirit of stdlib's functools
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache>=1.0.3:../../devel/py-backports.functools_lru_cache
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	more-itertools setuptools_scm:build

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
