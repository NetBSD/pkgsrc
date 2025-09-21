# $NetBSD: Makefile,v 1.34 2025/09/21 15:34:54 wiz Exp $

DISTNAME=	click-8.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://palletsprojects.com/p/click/
COMMENT=	Simple wrapper around optparse for powerful command line utilities
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
