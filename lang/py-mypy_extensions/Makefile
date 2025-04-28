# $NetBSD: Makefile,v 1.6 2025/04/28 19:44:29 adam Exp $

DISTNAME=	mypy_extensions-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy_extensions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mypy-lang.org/
COMMENT=	Experimental type system extensions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
