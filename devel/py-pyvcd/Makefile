# $NetBSD: Makefile,v 1.7 2026/10/24 09:28:12 adam Exp $

DISTNAME=	pyvcd-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvcd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/westerndigitalcorporation/pyvcd
COMMENT=	Package to write Value Change Dump (VCD) files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.9.13:../../devel/py-uv-build

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
