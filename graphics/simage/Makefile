# $NetBSD: Makefile,v 1.31 2023/01/03 17:36:27 wiz Exp $

DISTNAME=		simage-1.7.0
PKGREVISION=		9
CATEGORIES=		graphics
MASTER_SITES=		https://bitbucket.org/Coin3D/coin/downloads/

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
