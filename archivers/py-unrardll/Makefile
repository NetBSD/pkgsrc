# $NetBSD: Makefile,v 1.4 2024/01/24 23:49:00 adam Exp $

DISTNAME=	unrardll-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unrardll/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kovidgoyal/unrardll
COMMENT=	Python bindings for libunrar
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=57.4.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../archivers/libunrar/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
