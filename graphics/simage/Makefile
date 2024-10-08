# $NetBSD: Makefile,v 1.34 2024/10/08 20:43:17 rjs Exp $

DISTNAME=		simage-1.8.3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=coin3d/}
GITHUB_PROJECT=		simage
GITHUB_TAG=		v1.8.3

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Library for image format loaders and front-ends
LICENSE=		public-domain

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-xwd --with-mpeg2enc

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
