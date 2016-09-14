# $NetBSD: Makefile,v 1.5 2016/09/14 00:44:35 khorben Exp $
#

DISTNAME=	DeforaOS-Artwork-0.1.3
PKGNAME=	deforaos-icon-theme-0.1.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.defora.org/os/download/download/4451/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/os/project/4342/DeforaOS%20Artwork
COMMENT=	Artwork for the DeforaOS desktop
LICENSE=	cc-by-sa-v3.0

BUILD_DEPENDS+=	awesome-ttf-[0-9]*:../../fonts/awesome-ttf
BUILD_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
