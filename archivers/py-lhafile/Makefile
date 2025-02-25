# $NetBSD: Makefile,v 1.7 2025/02/25 08:04:09 adam Exp $

DISTNAME=	lhafile-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lhafile/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/FrodeSolheim/python-lhafile
COMMENT=	LHA(.lzh) file extract interface
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
