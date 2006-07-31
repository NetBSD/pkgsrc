# $NetBSD: Makefile,v 1.18 2006/07/31 21:43:55 jmmv Exp $
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

# gcc 4.x generates code that produces background noise during playback.
# Disabling optimizations when using this compiler solves the problem.
.if !empty(CC_VERSION:Mgcc-4*)
CFLAGS+=		-O0
CXXFLAGS+=		-O0
.endif
