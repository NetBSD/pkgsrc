# $NetBSD: Makefile,v 1.5 2019/08/12 07:26:49 adam Exp $

DISTNAME=	whichcraft-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whichcraft/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/pydanny/whichcraft
COMMENT=	Cross-platform cross-python shutil.which functionality
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.23.0:../../devel/py-wheel

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
