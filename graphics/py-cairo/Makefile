# $NetBSD: Makefile,v 1.82 2023/11/14 16:08:43 wiz Exp $

DISTNAME=	pycairo-1.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycairo/}

MAINTAINER=	leuzi@trash.net
HOMEPAGE=	https://cairographics.org/pycairo/
COMMENT=	Python bindings for cairo
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
