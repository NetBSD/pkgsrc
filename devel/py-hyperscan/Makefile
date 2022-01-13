# $NetBSD: Makefile,v 1.7 2022/01/13 19:31:23 wiz Exp $

DISTNAME=	hyperscan-0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperscan/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/darvid/python-hyperscan
COMMENT=	CPython extension for hyperscan
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

.include "../../devel/hyperscan/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
