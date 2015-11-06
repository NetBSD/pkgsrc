# $NetBSD: Makefile,v 1.1 2015/11/06 09:46:51 wiz Exp $

DISTNAME=	click-log-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/click-contrib/click-log
COMMENT=	Logging integration for Click
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
