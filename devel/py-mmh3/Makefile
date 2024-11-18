# $NetBSD: Makefile,v 1.3 2024/11/18 17:33:25 adam Exp $

DISTNAME=	mmh3-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mmh3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hajimes/mmh3
COMMENT=	Python wrapper for MurmurHash3
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=74.1.0:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
