# $NetBSD: Makefile,v 1.10 2005/03/16 21:27:00 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		1

DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-mp3/--enable-mp3/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-oss/--enable-oss/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-vorbis/--enable-vorbis/}

# XXX Workaround a crash during shutdown that happens when dlclose(3)ing
# any open plugin.  libstdc++ gets dynamically linked in when the id3lib
# library is loaded, and is the one causing problems.  See PR pkg/26846
# for more information.
USE_LANGUAGES=		c c++
LDFLAGS.NetBSD=		-lstdc++ -lm

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
