# $NetBSD: Makefile,v 1.2 2026/09/29 09:19:48 adam Exp $

DISTNAME=	nanobind-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nanobind/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wjakob/nanobind
COMMENT=	Tiny and efficient C++/Python bindings
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.10:../../devel/py-scikit-build-core

USE_LANGUAGES=	# none
USE_TOOLS+=	cmake

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
