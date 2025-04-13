# $NetBSD: Makefile,v 1.8 2025/04/13 08:06:22 adam Exp $

DISTNAME=	lhafile-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lhafile/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/FrodeSolheim/python-lhafile
COMMENT=	LHA(.lzh) file extract interface
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
