# $NetBSD: Makefile,v 1.1.1.1 2007/09/04 21:46:32 drochner Exp $

DISTNAME=	gcompris-8.3.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcompris/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://ofset.sourceforge.net/gcompris/
COMMENT=	Educational games for children

USE_TOOLS+=		gmake intltool gtar pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CHECK_PORTABILITY_SKIP+= macosx/build-gtk.sh
USE_DIRS+=	xdg-1.1 gnome2-1.5
INFO_FILES=	yes

DEPENDS+=	gnuchess-[0-9]*:../../games/gnuchess

PKG_SUPPORTED_OPTIONS=	gnet
PKG_OPTIONS_VAR=	PKG_OPTIONS.gcompris
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mgnet)
CONFIGURE_ARGS+=	--enable-gnet
.include "../../net/gnet/buildlink3.mk"
.endif

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
