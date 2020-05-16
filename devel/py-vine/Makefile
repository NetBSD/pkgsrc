# $NetBSD: Makefile,v 1.6 2020/05/16 17:38:40 adam Exp $

DISTNAME=	vine-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vine.readthedocs.io/
COMMENT=	Promises, promises, promises
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
