#	$NetBSD: Makefile,v 1.1 2020/08/18 20:13:31 riastradh Exp $

DISTNAME=	pyxbe-0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/^py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyxbe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mborgerson/pyxbe
COMMENT=	Python 3 library to work with .xbe files
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
