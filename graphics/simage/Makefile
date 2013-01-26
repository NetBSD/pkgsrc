# $NetBSD: Makefile,v 1.19 2013/01/26 21:36:32 adam Exp $

DISTNAME=		simage-1.6.1
PKGREVISION=		12
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Library for image format loaders and front-ends

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
.include "../../mk/giflib.buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
