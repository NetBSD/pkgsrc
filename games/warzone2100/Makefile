# $NetBSD: Makefile,v 1.27 2019/05/29 19:52:49 adam Exp $
#

DISTNAME=	warzone2100-3.2.3
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=warzone2100/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wz2100.net/
COMMENT=	Real-time strategy and real-time tactics hybrid computer game
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config bison msgfmt intltool gmake gawk flex unzip zip
FLEX_REQD=	2.5.35

.include "../../games/warzone2100/options.mk"

CONFIGURE_ARGS+=	--with-distributor=pkgsrc

LDFLAGS.DragonFly=	-lX11 -lintl

post-build:
	cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${MAKE} update-gmo

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
