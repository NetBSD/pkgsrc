#	$NetBSD: Makefile,v 1.2 2022/01/04 20:53:48 wiz Exp $

DISTNAME=	pyxbe-0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/^py//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyxbe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mborgerson/pyxbe
COMMENT=	Python 3 library to work with .xbe files
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
