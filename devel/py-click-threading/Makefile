# $NetBSD: Makefile,v 1.2 2016/08/01 10:55:52 wiz Exp $

DISTNAME=	click-threading-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-threading/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/click-contrib/click-threading
COMMENT=	Multithreaded Click apps made easy
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
