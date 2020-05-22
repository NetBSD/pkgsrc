# $NetBSD: Makefile,v 1.37 2020/05/22 10:56:10 adam Exp $

DISTNAME=	supertuxkart-1.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=supertuxkart/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://supertuxkart.net/Main_Page
COMMENT=	Free 3D kart racing game
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config

CMAKE_ARGS+=	-DUSE_WIIUSE=OFF
CMAKE_ARGS+=	-DBUILD_RECORDER=OFF

# Needs linux joystick support.
CMAKE_ARGS+=	-DENABLE_WAYLAND_DEVICE=OFF

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
.endif

# lib/mcpp/eval.c: In function 'eval_if':
# lib/mcpp/eval.c:361:44: error: array subscript has type 'char' [-Werror=char-subscripts]
#                  , opname[ op], prec, opname[ opp->op], opp->prec, opp->skip);
#                                             ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
