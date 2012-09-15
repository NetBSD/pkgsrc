# $NetBSD: Makefile,v 1.9 2012/09/15 10:04:44 obache Exp $

DISTNAME=	warmux-11.01
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/warmux/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.warmux.org/
COMMENT=	Battle game
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fribidi
CONFIGURE_ARGS+=	--enable-servers

BUILDLINK_TRANSFORM+=	rm:-Wl,--as-needed

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
