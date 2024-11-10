# $NetBSD: Makefile,v 1.5 2024/11/10 09:16:24 adam Exp $

DISTNAME=	makefun-1.15.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/makefun/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/smarie/python-makefun
COMMENT=	Small library to dynamically create Python functions
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
