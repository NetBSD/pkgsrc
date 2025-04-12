# $NetBSD: Makefile,v 1.5 2025/04/12 12:08:14 adam Exp $

DISTNAME=	mmh3-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mmh3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hajimes/mmh3
COMMENT=	Python wrapper for MurmurHash3
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
