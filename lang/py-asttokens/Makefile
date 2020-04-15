# $NetBSD: Makefile,v 1.13 2020/04/15 22:54:57 joerg Exp $

DISTNAME=	asttokens-2.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asttokens/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gristlabs/asttokens
COMMENT=	Annotate AST trees with source code positions
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-astroid-[0-9]*:../../devel/py-astroid
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == py27
TEST_DEPENDS=	# none; py-astroid is incompatible to py27
do-test:
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
