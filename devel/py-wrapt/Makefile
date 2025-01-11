# $NetBSD: Makefile,v 1.20 2025/01/11 20:27:56 adam Exp $

DISTNAME=	wrapt-1.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wrapt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GrahamDumpleton/wrapt
COMMENT=	Python module for decorators, wrappers and monkey patching
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
