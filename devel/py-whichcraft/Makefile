# $NetBSD: Makefile,v 1.4 2018/11/15 10:24:26 adam Exp $

DISTNAME=	whichcraft-0.5.2
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
