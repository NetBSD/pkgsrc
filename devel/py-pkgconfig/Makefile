# $NetBSD: Makefile,v 1.2 2016/04/08 13:17:48 wiz Exp $

DISTNAME=	pkgconfig-1.1.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=        1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pkgconfig/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/matze/pkgconfig
COMMENT=	Python wrapper for pkg-config
LICENSE=	mit

USE_TOOLS+=	pkg-config:run

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
