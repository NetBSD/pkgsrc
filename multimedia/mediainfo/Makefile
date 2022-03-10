# $NetBSD: Makefile,v 1.16 2022/03/10 15:05:05 ryoon Exp $

.include "../../multimedia/mediainfo/Makefile.common"

PKGNAME=		mediainfo-${MIVER}
LICENSE=		2-clause-bsd

USE_TOOLS+=		autoconf automake autoreconf gmake pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

CONFIGURE_DIRS+=	MediaInfo/Project/GNU/CLI

pre-configure:
	cd ${WRKSRC}/${CONFIGURE_DIRS:Q} && autoreconf -i

.include "../../multimedia/libmediainfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
