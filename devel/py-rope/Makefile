# $NetBSD: Makefile,v 1.37 2023/11/07 22:38:00 wiz Exp $

DISTNAME=	rope-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rope/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-rope/rope
COMMENT=	Python refactoring library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-toolconfig>=1.2.2:../../devel/py-toolconfig
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
