# $NetBSD: Makefile,v 1.8 2026/11/08 18:14:12 wiz Exp $

DISTNAME=	mypy_extensions-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy_extensions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mypy-lang.org/
COMMENT=	Experimental type system extensions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
