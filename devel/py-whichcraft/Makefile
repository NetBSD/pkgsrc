# $NetBSD: Makefile,v 1.2 2016/06/09 06:23:39 wiz Exp $

DISTNAME=	whichcraft-0.1.1
GITHUB_PROJECT=	whichcraft
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pydanny/}
EXTRACT_SUFX=	.zip

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/pydanny/whichcraft/
COMMENT=	Cross-platform cross-python shutil.which functionality
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-wheel>=0.23.0:../../devel/py-wheel

USE_LANGUAGES=	# none

WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
