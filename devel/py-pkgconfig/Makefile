# $NetBSD: Makefile,v 1.7 2019/04/04 09:30:05 adam Exp $

DISTNAME=	pkgconfig-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkgconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matze/pkgconfig
COMMENT=	Python wrapper for pkg-config
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.0:../../devel/py-nose

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config:run

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
