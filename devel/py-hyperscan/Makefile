# $NetBSD: Makefile,v 1.6 2022/01/04 20:53:10 wiz Exp $

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

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.11.1:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../devel/hyperscan/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
