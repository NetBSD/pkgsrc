# $NetBSD: Makefile,v 1.2 2022/01/04 20:52:56 wiz Exp $

DISTNAME=	click-plugins-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-plugins/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/click-plugins/
COMMENT=	CLI command extension for click
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
