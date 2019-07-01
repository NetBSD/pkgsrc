# $NetBSD: Makefile,v 1.14 2019/07/01 15:13:20 nia Exp $

PKGNAME=		supertux-0.6.0
DISTNAME=		SuperTux-v${PKGVERSION_NOREV}-Source
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=SuperTux/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		https://www.supertux.org/
COMMENT=		2D jump\'n run game in the style of the Super Mario ones
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
CMAKE_ARGS+=		-DINSTALL_SUBDIR_BIN=bin
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=off
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
