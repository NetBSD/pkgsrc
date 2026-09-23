# $NetBSD: Makefile,v 1.4 2026/09/23 12:50:01 adam Exp $

DISTNAME=	xdg_base_dirs-6.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xdg_base_dirs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/srstevenson/xdg-base-dirs
COMMENT=	Variables defined by the XDG Base Directory Specification
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.7.19:../../devel/py-uv-build

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
