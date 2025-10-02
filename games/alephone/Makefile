# $NetBSD: Makefile,v 1.42 2025/10/02 11:19:51 adam Exp $

DISTNAME=	AlephOne-20250829
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES+=	${MASTER_SITE_GITHUB:=Aleph-One-Marathon/}
GITHUB_PROJECT=	alephone
GITHUB_RELEASE=	${DISTNAME:S/AlephOne/release/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	https://alephone.lhowon.org/
COMMENT=	Classic 2.5D FPS game engine, updated to use SDL
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost=${PREFIX}

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-headers+=	boost-headers>=1.53
.include "../../devel/boost-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs>=1.53
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
