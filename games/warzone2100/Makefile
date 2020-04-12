# $NetBSD: Makefile,v 1.36 2020/04/12 08:28:45 adam Exp $

DISTNAME=	warzone2100-3.3.0_src
PKGNAME=	${DISTNAME:S/_src//}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=warzone2100/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wz2100.net/
COMMENT=	Real-time strategy and real-time tactics hybrid computer game
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config zip
USE_TOOLS+=	msgfmt msgmerge xgettext

# Could NOT find Gettext: Found unsuitable version "0.16.1", but
# required is at least "0.18"
_TOOLS_USE_PKGSRC.msgfmt=	yes
_TOOLS_USE_PKGSRC.msgmerge=	yes
_TOOLS_USE_PKGSRC.xgettext=	yes

.include "../../games/warzone2100/options.mk"

WRKSRC=		${WRKDIR}/warzone2100

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=		-DCMAKE_MAKE_PROGRAM=${MAKE_PROGRAM} -DWZ_DISTRIBUTOR=pkgsrc

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
LDFLAGS.DragonFly=	-lX11 -lintl

BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	${RUN} mkdir -p ${WRKSRC}/build

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/quesoglc/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
