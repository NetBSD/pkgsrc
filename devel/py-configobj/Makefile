# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:04 wiz Exp $

DISTNAME=	configobj-5.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/configobj/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/DiffSK/configobj
COMMENT=	Config file reading, writing and validation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
