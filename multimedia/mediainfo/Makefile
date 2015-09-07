# $NetBSD: Makefile,v 1.14 2015/09/07 01:02:00 dsainty Exp $

.include "../../multimedia/mediainfo/Makefile.common"

PKGNAME=		mediainfo-${MIVER}
LICENSE=		gnu-lgpl-v3

USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_DIRS+=	MediaInfo/Project/GNU/CLI

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS:Q} && autoreconf -i

.include "../../multimedia/libmediainfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
