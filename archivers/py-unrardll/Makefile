# $NetBSD: Makefile,v 1.5 2024/11/11 07:27:51 wiz Exp $

DISTNAME=	unrardll-0.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unrardll/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kovidgoyal/unrardll
COMMENT=	Python bindings for libunrar
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=57.4.0:../../devel/py-setuptools

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../archivers/libunrar/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
