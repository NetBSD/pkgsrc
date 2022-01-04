# $NetBSD: Makefile,v 1.14 2022/01/04 20:53:05 wiz Exp $

DISTNAME=	flake8-import-order-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-import-order/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/flake8-import-order
COMMENT=	Flake8 and pylama plugin that checks the ordering of import statements
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-asttokens-[0-9]*:../../lang/py-asttokens
DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-lama-[0-9]*:../../devel/py-lama

PYTHON_VERSIONED_DEPENDENCIES=	test:test

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
