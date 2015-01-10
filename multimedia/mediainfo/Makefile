# $NetBSD: Makefile,v 1.13 2015/01/10 20:35:24 wiz Exp $

.include "../../multimedia/mediainfo/Makefile.common"

PKGNAME=		mediainfo-${MIVER}
LICENSE=		gnu-lgpl-v3

USE_TOOLS+=		autoconf automake gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_DIRS+=	MediaInfo/Project/GNU/CLI

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && autoreconf -i

.include "../../multimedia/libmediainfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
