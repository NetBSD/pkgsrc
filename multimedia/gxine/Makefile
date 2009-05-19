# $NetBSD: Makefile,v 1.38 2009/05/19 07:07:50 abs Exp $

DISTNAME=	gxine-0.5.904
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xinehq.de/
COMMENT=	Gtk-based media player

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--disable-lirc
USE_DIRS+=		xdg-1.1

BROKEN_GETTEXT_DETECTION=	yes
PTHREAD_OPTS+=			require

EGDIR=			${PREFIX}/share/examples/gxine
PKG_SYSCONFSUBDIR=	gxine

.for f in gtkrc keypad.xml startup toolbar-fullscreen.xml toolbar-window.xml
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../www/firefox/buildlink3.mk"
# XXX does not work with pkgsrc firefox3
#.include "../../www/firefox3/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
