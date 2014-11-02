# $NetBSD: Makefile,v 1.1 2014/11/02 18:22:11 khorben Exp $
#

DISTNAME=	DeforaOS-Artwork-0.0.0
PKGNAME=	deforaos-icon-theme-0.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.defora.org/os/download/download/4341/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/os/download/download/4341/
COMMENT=	Artwork for the DeforaOS desktop
LICENSE=	cc-by-sa-v3.0

BUILD_DEPENDS+=	awesome-ttf-[0-9]*:../../fonts/awesome-ttf
BUILD_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
