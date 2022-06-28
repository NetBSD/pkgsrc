# $NetBSD: Makefile,v 1.132 2022/06/28 11:34:00 wiz Exp $

DISTNAME=	libgd-2.3.3
PKGNAME=	${DISTNAME:S/libgd/gd/}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgd/}
GITHUB_PROJECT=	libgd
GITHUB_RELEASE=	gd-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://libgd.github.io/
COMMENT=	Graphics library for the dynamic creation of images

.include "options.mk"

USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--with-fontconfig=${BUILDLINK_PREFIX.fontconfig}
CONFIGURE_ARGS+=	--with-freetype=${BUILDLINK_PREFIX.freetype2}
CONFIGURE_ARGS+=	--with-jpeg=${JPEGBASE}
CONFIGURE_ARGS+=	--with-liq=${BUILDLINK_PREFIX.libimagequant}
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-webp=${BUILDLINK_PREFIX.libwebp}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
REPLACE_PERL+=		src/bdftogd
PTHREAD_AUTO_VARS=	yes
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
