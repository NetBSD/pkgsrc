# $NetBSD: Makefile,v 1.3 2024/10/22 07:55:12 adam Exp $

DISTNAME=	enzyme-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_PYPI:=e/enzyme/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Diaoul/enzyme
COMMENT=	Python module to parse video metadata
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
