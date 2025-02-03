# $NetBSD: Makefile,v 1.7 2025/02/03 08:51:15 adam Exp $

DISTNAME=	mando-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mando/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://mando.readthedocs.io/
COMMENT=	Create Python CLI apps with little to no effort at all
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
