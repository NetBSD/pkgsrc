# $NetBSD: Makefile,v 1.2 2024/11/22 21:56:23 wiz Exp $

DISTNAME=	orca-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orca/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/UDST/orca
COMMENT=	Python library for task orchestration
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.15.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-tables>=3.1:../../math/py-tables
DEPENDS+=	${PYPKGPREFIX}-toolz>=0.8.1:../../devel/py-toolz

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
