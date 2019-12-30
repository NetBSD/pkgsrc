# $NetBSD: Makefile,v 1.1 2019/12/30 00:52:30 mef Exp $

VERSION=	0.5.8
DISTNAME=	wand-${VERSION}
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=emcconville/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.wand-py.org/
COMMENT= 	Ctypes-based simple ImageMagick binding for Python
LICENSE=	mit

EGG_NAME=	Wand-${VERSION}
PKGCONFIG_OVERRIDE+=	Wand.pc.in

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
