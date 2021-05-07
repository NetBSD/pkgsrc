# $NetBSD: Makefile,v 1.8 2021/05/07 17:55:20 adam Exp $

DISTNAME=	vine-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vine.readthedocs.io/
COMMENT=	Special implementation of promises
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
