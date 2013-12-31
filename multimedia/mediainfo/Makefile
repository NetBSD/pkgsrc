# $NetBSD: Makefile,v 1.12 2013/12/31 23:19:46 ryoon Exp $

.include "../../multimedia/mediainfo/Makefile.common"

PKGNAME=		${DISTNAME:S/mediainfo_/mediainfo-/S/_AllInclusive//}
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
