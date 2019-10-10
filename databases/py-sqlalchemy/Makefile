# $NetBSD: Makefile,v 1.57 2019/10/10 18:22:49 adam Exp $

DISTNAME=	SQLAlchemy-1.3.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SQLAlchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sqlalchemy.org/
COMMENT=	Python SQL toolkit and Object Relational Mapper
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.5.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

REPLACE_PYTHON=	lib/sqlalchemy/testing/runner.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
