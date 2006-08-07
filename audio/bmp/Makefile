# $NetBSD: Makefile,v 1.19 2006/08/07 11:21:45 wiz Exp $
#

BMP_ENABLE_ENCODERS=	yes

.include "Makefile.common"

DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	CDAUDIO="@comment "
.else
PLIST_SUBST+=	CDAUDIO=""
.endif
PRINT_PLIST_AWK+=	/cdaudio/ { print "$${CDAUDIO}" $$0; next }

# XXX Workaround a crash during shutdown that happens when dlclose(3)ing
# any open plugin.  libstdc++ gets dynamically linked in when the id3lib
# library is loaded, and is the one causing problems.  See PR pkg/26846
# for more information.
USE_LANGUAGES=		c c++
LDFLAGS.NetBSD+=	-lstdc++ -lm

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
