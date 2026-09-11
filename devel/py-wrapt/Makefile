# $NetBSD: Makefile,v 1.36 2026/09/11 11:07:13 adam Exp $

DISTNAME=	wrapt-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wrapt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GrahamDumpleton/wrapt
COMMENT=	Python module for decorators, wrappers and monkey patching
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
