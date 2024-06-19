# $NetBSD: Makefile,v 1.77 2024/06/19 09:49:58 adam Exp $

DISTNAME=	SQLAlchemy-2.0.31
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.24:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=47:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.18:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
