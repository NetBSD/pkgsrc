# $NetBSD: Makefile,v 1.17 2022/01/04 20:54:08 wiz Exp $

DISTNAME=	asttokens-2.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asttokens/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gristlabs/asttokens
COMMENT=	Annotate AST trees with source code positions
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-astroid-[0-9]*:../../devel/py-astroid
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	pip:build

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
TEST_DEPENDS=	# none; test depends are incompatible to py27
do-test:
.endif

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
