# $NetBSD: Makefile,v 1.1 2025/04/23 14:54:31 wiz Exp $

DISTNAME=	pydiffx-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydiffx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://diffx.org/pydiffx/
COMMENT=	Python module for reading and writing DiffX files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-kgb>=0:../../devel/py-kgb

USE_LANGUAGES=	# none

# as of 1.1
# 68 failed, 108 passed
# https://github.com/beanbaginc/kgb/issues/12

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
