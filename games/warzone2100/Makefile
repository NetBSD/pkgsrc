# $NetBSD: Makefile,v 1.4 2009/03/22 19:01:38 wiz Exp $
#

DISTNAME=	warzone2100-2.1.1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/warzone/releases/2.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wz2100.net/
COMMENT=	Real-time strategy and real-time tactics hybrid computer game

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	pkg-config bison msgfmt intltool gmake gsed gawk flex
TOOLS_PLATFORM.gsed=	#empty, override nonsense in tools

CONFIGURE_ARGS+=	--with-distributor=pkgsrc

CHECK_WRKREF_SKIP=	share/warzone2100/mods/global/aivolution.wz

.include "../../audio/openal/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
BUILDLINK_API_DEPENDS.flex+=	flex>=2.5.35
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/quesoglc/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
