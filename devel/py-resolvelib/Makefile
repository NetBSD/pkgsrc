# $NetBSD: Makefile,v 1.7 2025/04/12 20:13:33 adam Exp $

DISTNAME=	resolvelib-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/resolvelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sarugaku/resolvelib
COMMENT=	Resolve abstract dependencies into concrete ones
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
