# $NetBSD: Makefile,v 1.5 2004/09/08 12:06:28 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		1

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-mp3/--enable-mp3/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-oss/--enable-oss/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-vorbis/--enable-vorbis/}

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
