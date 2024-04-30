# $NetBSD: Makefile,v 1.9 2024/04/30 13:36:38 wiz Exp $

DISTNAME=	hyperscan-0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperscan/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/darvid/python-hyperscan
COMMENT=	CPython extension for hyperscan
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/hyperscan/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
