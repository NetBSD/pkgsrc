# $NetBSD: Makefile,v 1.40 2024/05/29 16:33:45 adam Exp $

DISTNAME=	lightspark-0.8.5
PKGREVISION=	22
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=lightspark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lightspark.github.io/
COMMENT=	Open source Flash player
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config msgfmt msgmerge
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DMANUAL_DIRECTORY=${PKGMANDIR}
CMAKE_ARGS+=	-DETCDIR=${PKG_SYSCONFDIR}

TOOL_DEPENDS+=	nasm>=1.1:../../devel/nasm

# MESSAGE(FATAL_ERROR "GCC 4.6+ is required.")
GCC_REQD+=	4.6

CONF_FILES+=	${PREFIX}/share/examples/lightspark/xdg/lightspark.conf \
		${PKG_SYSCONFDIR}/xdg/lightspark.conf

.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../net/rtmpdump/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
