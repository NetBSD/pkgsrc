# $NetBSD: Makefile,v 1.2 2017/07/17 07:04:22 adam Exp $

DISTNAME=	vine-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vine.readthedocs.io/
COMMENT=	Promises, promises, promises
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
