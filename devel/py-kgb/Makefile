# $NetBSD: Makefile,v 1.1 2025/04/23 14:53:30 wiz Exp $

DISTNAME=	kgb-7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kgb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/beanbaginc/kgb
COMMENT=	Utilities for spying on function calls in unit tests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 7.2
# 212 passed, 4 skipped, 1 error

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
