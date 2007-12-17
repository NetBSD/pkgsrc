# $NetBSD: Makefile,v 1.6 2007/12/17 23:45:40 wiz Exp $

DISTNAME=	gcompris-8.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gcompris/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://ofset.sourceforge.net/gcompris/
COMMENT=	Educational games for children

USE_TOOLS+=		gmake intltool gtar pkg-config msgfmt texi2html
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CHECK_PORTABILITY_SKIP+= macosx/build-gtk.sh
USE_DIRS+=	xdg-1.1 gnome2-1.5
INFO_FILES=	yes
#LICENSE=	gnu-gplv3

DEPENDS+=	gnuchess-[0-9]*:../../games/gnuchess

PTHREAD_AUTO_VARS=	yes

PKG_SUPPORTED_OPTIONS=	gnet
PKG_OPTIONS_VAR=	PKG_OPTIONS.gcompris
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mgnet)
CONFIGURE_ARGS+=	--enable-gnet
.include "../../net/gnet/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/py-sqlite2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
