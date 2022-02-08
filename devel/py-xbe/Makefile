# $NetBSD: Makefile,v 1.3 2022/02/08 10:53:25 adam Exp $

DISTNAME=	pyxbe-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyxbe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mborgerson/pyxbe
COMMENT=	Python 3 library to work with .xbe files
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
