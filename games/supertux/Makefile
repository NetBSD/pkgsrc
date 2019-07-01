# $NetBSD: Makefile,v 1.13 2019/07/01 04:08:17 ryoon Exp $

DISTNAME=		supertux-0.4.0
PKGREVISION=		10
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=SuperTux/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://supertux.lethargik.org/
COMMENT=		2D jump\'n run game in the style of the Super Mario ones
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=		yes
CMAKE_ARGS+=		-DINSTALL_SUBDIR_BIN=bin
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=off
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

CFLAGS+=	-I${BUILDLINK_DIR}/include/AL
LDFLAGS+=	-L${BUILDLINK_DIR}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_DIR}/lib

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
