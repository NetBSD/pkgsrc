# $NetBSD: Makefile,v 1.72 2023/07/30 15:32:48 adam Exp $

DISTNAME=	SQLAlchemy-1.4.48
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.4.18:../../devel/py-greenlet
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
