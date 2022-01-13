# $NetBSD: Makefile,v 1.18 2022/01/13 19:31:22 wiz Exp $

DISTNAME=	pluggy-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pluggy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pluggy
COMMENT=	Plugin and hook calling mechanisms for python
LICENSE=	mit

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=0.12:../../devel/py-importlib-metadata
.endif

PYTHON_VERSIONED_DEPENDENCIES=	test:test setuptools_scm:build

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} testing

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
