# $NetBSD: Makefile,v 1.27 2023/11/12 13:21:21 wiz Exp $

DISTNAME=	fs-uae-3.1.66
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	https://fs-uae.net/files/FS-UAE/Stable/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fs-uae.net/
COMMENT=	Amiga emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config zip
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libmpeg2

# Fails with C++14 default language.
FORCE_CXX_STD=		gnu++03

.include "../../mk/bsd.prefs.mk"

# See the configure script for the full conditions for whether
# the JIT is supported.
#error JIT is only supported on x86/x86-64
#error no JIT on OpenBSD/FreeBSD right now
.if (${MACHINE_ARCH} != "i386" && \
     ${MACHINE_ARCH} != "x86_64") || \
    ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-jit
.endif
# Requires paxctl +m even without jit.
NOT_PAX_MPROTECT_SAFE+=	bin/fs-uae

# src/debug.cpp: In function 'void debug()':
# src/debug.cpp:5361:188: error: array subscript has type 'char' [-Werror=char-subscripts]
# ... processname[command[0]] == 0 ...
#
# command[0] is the length of a pascal-style string.
# This may produce unexpected results with long process names.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.if ${OPSYS} != "Darwin"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.endif
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
