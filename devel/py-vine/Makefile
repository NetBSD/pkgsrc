# $NetBSD: Makefile,v 1.13 2025/04/12 21:37:07 adam Exp $

DISTNAME=	vine-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vine.readthedocs.io/
COMMENT=	Special implementation of promises
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

# test status as of 5.1.0
# 4 failed, 38 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
