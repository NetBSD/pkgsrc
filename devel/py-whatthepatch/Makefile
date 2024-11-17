# $NetBSD: Makefile,v 1.6 2024/11/17 09:51:40 wiz Exp $

DISTNAME=	whatthepatch-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whatthepatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cscorley/whatthepatch
COMMENT=	Patch parsing and application library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65.0.0:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 1.0.7
# 1 failed, 53 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
