# $NetBSD: Makefile,v 1.32 2020/01/27 19:35:54 triaxx Exp $

DISTNAME=	warzone2100-3.3.0_src
PKGNAME=	${DISTNAME:S/_src//}
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
USE_TOOLS+=	pkg-config bison msgfmt intltool gmake gawk flex unzip zip
FLEX_REQD=	2.5.35

.include "../../games/warzone2100/options.mk"

WRKSRC=		${WRKDIR}/warzone2100

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

CMAKE_ARGS+=		-DCMAKE_MAKE_PROGRAM=${MAKE_PROGRAM} -DWZ_DISTRIBUTOR=pkgsrc

CFLAGS+=		-Wno-error=unused-variable
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
LDFLAGS.DragonFly=	-lX11 -lintl

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
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
