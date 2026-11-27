# $NetBSD: Makefile,v 1.2 2026/11/27 05:58:14 adam Exp $

DISTNAME=	lazy_importer-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lazy-importer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pganssle/lazy_importer
COMMENT=	Context manager for portable, opt-in lazy imports
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.12:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
