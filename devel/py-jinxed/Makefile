# $NetBSD: Makefile,v 1.1 2026/06/28 08:55:07 adam Exp $

DISTNAME=	jinxed-2.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jinxed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Rockhopper-Technologies/jinxed
COMMENT=	Jinxed Terminal Library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
