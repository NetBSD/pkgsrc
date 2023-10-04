# $NetBSD: Makefile,v 1.35 2023/10/04 20:21:18 adam Exp $

DISTNAME=	rope-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-rope/rope
COMMENT=	Python refactoring library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-toolconfig>=1.2.2:../../devel/py-toolconfig
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
