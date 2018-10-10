# $NetBSD: Makefile,v 1.4 2018/10/10 15:41:16 minskim Exp $

DISTNAME=	hyperscan-0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperscan/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/darvid/python-hyperscan
COMMENT=	CPython extension for hyperscan
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.11.1:../../devel/py-setuptools_scm

.include "../../devel/hyperscan/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
