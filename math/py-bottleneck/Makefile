# $NetBSD: Makefile,v 1.22 2025/04/15 16:31:38 adam Exp $

DISTNAME=	bottleneck-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Bottleneck/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydata/bottleneck
COMMENT=	Collection of fast NumPy array functions written in C
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer-[0-9]*:../../devel/py-versioneer

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
