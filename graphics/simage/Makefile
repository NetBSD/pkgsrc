# $NetBSD: Makefile,v 1.39 2026/04/06 17:24:34 wiz Exp $

DISTNAME=		simage-1.8.3
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=coin3d/}
GITHUB_PROJECT=		simage
GITHUB_TAG=		v1.8.3

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.coin3d.org/
COMMENT=		Library for image format loaders and front-ends
LICENSE=		public-domain

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-xwd --with-mpeg2enc

CFLAGS+=		-Wno-implicit-function-declaration

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
