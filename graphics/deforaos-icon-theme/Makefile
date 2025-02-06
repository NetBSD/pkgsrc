# $NetBSD: Makefile,v 1.9 2025/02/06 01:16:23 khorben Exp $
#

DISTNAME=	DeforaOS-Artwork-0.1.4
PKGNAME=	deforaos-icon-theme-0.1.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=DeforaOS/}DeforaOS-Artwork/releases/download/DeforaOS-Artwork_0-1-4/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	Artwork for the DeforaOS desktop
LICENSE=	cc-by-sa-v3.0

TOOL_DEPENDS+=	awesome-ttf-[0-9]*:../../fonts/awesome-ttf
TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

ICON_THEMES=	yes

TEST_TARGET=	tests

.include "../../mk/bsd.pkg.mk"
