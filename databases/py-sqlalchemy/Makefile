# $NetBSD: Makefile,v 1.73 2024/03/06 21:40:57 wiz Exp $

DISTNAME=	SQLAlchemy-2.0.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.18:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.0:../../devel/py-typing-extensions

PYTHON_VERSIONS_INCOMPATIBLE=	27

# test status as of 2.0.28
# 2 failed, 20790 passed, 10754 skipped, 107 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
