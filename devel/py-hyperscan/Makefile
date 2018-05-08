# $NetBSD: Makefile,v 1.1 2018/05/08 16:54:50 minskim Exp $

DISTNAME=	hyperscan-0.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperscan/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/darvid/python-hyperscan
COMMENT=	CPython extension for hyperscan
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../devel/hyperscan/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
