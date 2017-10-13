# $NetBSD: Makefile,v 1.4 2017/10/13 07:04:28 adam Exp $

DISTNAME=	pkgconfig-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkgconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matze/pkgconfig
COMMENT=	Python wrapper for pkg-config
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose>=1.0:../../devel/py-nose

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config:run

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
