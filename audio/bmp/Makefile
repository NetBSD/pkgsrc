# $NetBSD: Makefile,v 1.1.1.1 2004/04/11 18:10:59 jmmv Exp $
#

.include "Makefile.common"

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-oss/--enable-oss/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-vorbis/--enable-vorbis/}

.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
