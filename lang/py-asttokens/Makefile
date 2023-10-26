# $NetBSD: Makefile,v 1.24 2023/10/26 13:09:46 adam Exp $

DISTNAME=	asttokens-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asttokens/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gristlabs/asttokens
COMMENT=	Annotate AST trees with source code positions
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-astroid-[0-9]*:../../devel/py-astroid
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	pip:build setuptools_scm:build

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
TEST_DEPENDS=	# none; test depends are incompatible to py27
do-test:
.endif

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
