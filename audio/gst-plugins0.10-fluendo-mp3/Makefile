# $NetBSD: Makefile,v 1.13 2012/09/15 10:03:37 obache Exp $
#

DISTNAME=		gst-fluendo-mp3-0.10.15
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		http://core.fluendo.com/gstreamer/src/gst-fluendo-mp3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fluendo.com/shop/product/fluendo-mp3-decoder/
COMMENT=		MP3 decoder for gstreamer
LICENSE=		mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-liboil

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../devel/liboil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
