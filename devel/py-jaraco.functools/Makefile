# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:12 wiz Exp $

DISTNAME=	jaraco.functools-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.functools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.functools
COMMENT=	Additional functools in the spirit of stdlib's functools
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache>=1.0.3:../../devel/py-backports.functools_lru_cache
.endif

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	more-itertools

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
