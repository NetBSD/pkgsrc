# $NetBSD: Makefile,v 1.18 2013/02/16 11:21:29 wiz Exp $
#

DISTNAME=	warzone2100-2.2.2
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=warzone2100/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wz2100.net/
COMMENT=	Real-time strategy and real-time tactics hybrid computer game

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config bison msgfmt intltool gmake gawk flex unzip zip
FLEX_REQD=	2.5.35

CONFIGURE_ARGS+=	--with-distributor=pkgsrc

LDFLAGS.DragonFly=	-lX11 -lintl

post-build:
	cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${MAKE} update-gmo

.include "../../audio/openal/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/quesoglc/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
