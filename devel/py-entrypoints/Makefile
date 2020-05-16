# $NetBSD: Makefile,v 1.4 2020/05/16 17:13:40 adam Exp $

DISTNAME=	entrypoints-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/entrypoints/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/takluyver/entrypoints
COMMENT=	Discover and load entry points from installed packages
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test:test

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-configparser>=3.5:../../devel/py-configparser
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
