# $NetBSD: Makefile,v 1.80 2014/02/12 23:18:17 tron Exp $

DISTNAME=	gxine-0.5.905
PKGREVISION=	32
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xine-project.org/home
COMMENT=	Gtk-based media player

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--disable-lirc

BROKEN_GETTEXT_DETECTION=	yes
PTHREAD_OPTS+=			require
# for svg->png icon conversion
# XXX librsvg>=2.32 doesn't install the "rsvg" tool
#BUILD_DEPENDS+=		librsvg-[0-9]*:../../graphics/librsvg

EGDIR=			${PREFIX}/share/examples/gxine
PKG_SYSCONFSUBDIR=	gxine

.for f in gtkrc keypad.xml startup toolbar-fullscreen.xml toolbar-window.xml
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/xulrunner192/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
