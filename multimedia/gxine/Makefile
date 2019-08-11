# $NetBSD: Makefile,v 1.110 2019/08/11 13:22:03 wiz Exp $

DISTNAME=	gxine-0.5.910
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xine/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xine-project.org/home
COMMENT=	Gtk-based media player
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config perl:build
USE_TOOLS+=		msgfmt msgmerge xgettext
USE_LANGUAGES=		c99
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--disable-lirc
CONFIGURE_ARGS+=	--with-gtk3
CONFIGURE_ARGS+=	--with-xcb
CONFIGURE_ARGS+=	--without-browser-plugin

BUILD_DEFS+=		PKG_SYSCONFBASE

BROKEN_GETTEXT_DETECTION=	yes
PTHREAD_OPTS+=			require

# spidermonkey185
NOT_PAX_MPROTECT_SAFE+=	bin/gxine

EGDIR=			${PREFIX}/share/examples/gxine
PKG_SYSCONFSUBDIR=	gxine

.for f in gtk.css gtkrc keypad.xml startup toolbar-fullscreen.xml toolbar-window.xml
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../lang/spidermonkey185/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
