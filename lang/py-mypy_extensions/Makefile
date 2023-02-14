# $NetBSD: Makefile,v 1.5 2023/02/14 19:09:59 adam Exp $

DISTNAME=	mypy_extensions-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mypy_extensions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mypy-lang.org/
COMMENT=	Experimental type system extensions
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
