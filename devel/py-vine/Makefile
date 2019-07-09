# $NetBSD: Makefile,v 1.5 2019/07/09 11:35:14 nia Exp $

DISTNAME=	vine-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vine.readthedocs.io/
COMMENT=	Promises, promises, promises
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
