# $NetBSD: Makefile,v 1.7 2004/10/03 00:13:05 tv Exp $
#

.include "Makefile.common"

PKGREVISION=		3

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-mp3/--enable-mp3/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-oss/--enable-oss/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-vorbis/--enable-vorbis/}

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
