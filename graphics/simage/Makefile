# $NetBSD: Makefile,v 1.1.1.1 2004/11/11 06:16:26 minskim Exp $

DISTNAME=		simage-1.6.1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.coin3d.org/
COMMENT=		Library for image format loaders and front-ends

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-xwd --with-mpeg2enc

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
