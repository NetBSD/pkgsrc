# $NetBSD: Makefile,v 1.2 2015/01/14 01:29:32 khorben Exp $
#

DISTNAME=	DeforaOS-Artwork-0.1.0
PKGNAME=	deforaos-icon-theme-0.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.defora.org/os/download/download/4344/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/os/download/download/4344/
COMMENT=	Artwork for the DeforaOS desktop
LICENSE=	cc-by-sa-v3.0

BUILD_DEPENDS+=	awesome-ttf-[0-9]*:../../fonts/awesome-ttf
BUILD_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
