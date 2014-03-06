# $NetBSD: Makefile,v 1.42 2014/03/06 10:16:15 mrg Exp $

DISTNAME=	hydrogen-0.9.6-beta3
PKGNAME=	hydrogen-0.9.6.beta3
CATEGORIES=	audio
MASTER_SITES=	https://github.com/hydrogen-music/hydrogen/archive/

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

MAKE_ENV+=	QTDIR=${PREFIX}/qt4 PATH=$$PATH:${PREFIX}/qt4/bin

USE_CMAKE=	yes
CMAKE_ARGS+=	-DWANT_OSS=ON
CMAKE_ARGS+=	-DWANT_LIBARCHIVE=ON
CMAKE_ARGS+=	-DWANT_JACK=OFF
CMAKE_ARGS+=	-DWANT_LRDF=OFF

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CMAKE_ARGS+=	-DWANT_ALSA=ON
.else
CMAKE_ARGS+=	-DWANT_ALSA=OFF
.endif

.include "../../archivers/libarchive/buildlink3.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
