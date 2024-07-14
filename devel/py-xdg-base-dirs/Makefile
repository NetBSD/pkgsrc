# $NetBSD: Makefile,v 1.1 2024/07/14 10:16:28 wiz Exp $

DISTNAME=	xdg_base_dirs-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xdg_base_dirs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/srstevenson/xdg-base-dirs
COMMENT=	Variables defined by the XDG Base Directory Specification
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
