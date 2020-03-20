# $NetBSD: Makefile,v 1.20 2020/03/20 11:57:40 nia Exp $

DISTNAME=		chromium-bsu-0.9.16.1
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chromium-bsu/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chromium-bsu.sourceforge.net/
COMMENT=		Fast paced, arcade-style, top-scrolling space shooter

DEPENDS=		uralic-ttf-[0-9]*:../../fonts/uralic-ttf

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		msgfmt msgmerge xgettext
GNU_CONFIGURE=		yes

# XXX needs gnu msgfmt for desktop file creation
_TOOLS_USE_PKGSRC.msgfmt=	yes

LDFLAGS+=		${BUILDLINK_LDADD.gettext}
LDFLAGS.DragonFly=	-lSDL2
LDFLAGS.SunOS=		-lSDL2

CONFIGURE_ARGS+=	--disable-ftgl
CONFIGURE_ARGS+=	--disable-glut
# detection fails
CONFIGURE_ARGS+=	--disable-glpng
# we don't want SDL1.
CONFIGURE_ARGS+=	--disable-sdl
CONFIGURE_ARGS+=	--disable-sdlmixer
CONFIGURE_ARGS+=	--disable-sdlimage
CONFIGURE_ARGS+=	--disable-openal

CFLAGS+=		-DWITH_JOYSTICK

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/quesoglc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
