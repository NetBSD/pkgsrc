# $NetBSD: Makefile,v 1.12 2024/11/11 07:28:29 wiz Exp $

DISTNAME=	vine-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vine.readthedocs.io/
COMMENT=	Special implementation of promises
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# test status as of 5.1.0
# 4 failed, 38 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
