# $NetBSD: Makefile,v 1.17 2025/04/12 09:50:46 adam Exp $

DISTNAME=	configobj-5.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/configobj/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/DiffSK/configobj
COMMENT=	Config file reading, writing and validation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
