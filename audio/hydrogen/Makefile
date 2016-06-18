# $NetBSD: Makefile,v 1.51 2016/06/18 11:24:54 ryoon Exp $

DISTNAME=	Hydrogen-0.9.6.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hydrogen-music/}
GITHUB_PROJECT=	Hydrogen
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.hydrogen-music.org/
COMMENT=	Real time drum machine/sequencer
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

MAKE_ENV+=	QTDIR=${PREFIX}/qt4 PATH=$$PATH:${PREFIX}/qt4/bin
#CONFIGURE_ENV+=	LADSPA_PATH=${BUILDLINK_PREFIX.ladspa}/lib/ladspa

USE_CMAKE=	yes
CMAKE_ARGS+=	-DWANT_OSS=ON
CMAKE_ARGS+=	-DWANT_JACK=OFF
CMAKE_ARGS+=	-DWANT_LRDF=OFF
# options.mk this, and ladspa.
CMAKE_ARGS+=	-DWANT_PULSEAUDIO=OFF
# NetBSD libarchive is old?
CMAKE_ARGS+=	-DWANT_LIBARCHIVE=OFF
CMAKE_ARGS+=	-DWANT_LIBTAR=ON

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CMAKE_ARGS+=	-DWANT_ALSA=ON
.else
CMAKE_ARGS+=	-DWANT_ALSA=OFF
.endif

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/libtar/buildlink3.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/libsndfile/buildlink3.mk"
#.include "../../audio/ladspa/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
