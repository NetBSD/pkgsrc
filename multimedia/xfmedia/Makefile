# $NetBSD: Makefile,v 1.34 2012/10/02 17:11:44 tron Exp $
#

DISTNAME=		xfmedia-0.9.2
PKGREVISION=		15
CATEGORIES=		multimedia
MASTER_SITES=		http://spuriousinterrupt.org/projects/xfmedia/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://spuriousinterrupt.org/projects/xfmedia/
COMMENT=		Xfce media player based on xine

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

OWN_DIRS=	${PKG_SYSCONFDIR}/xdg/xfmedia

CONF_FILES=	${PREFIX}/share/xfmedia/keybindings.rc \
		${PKG_SYSCONFDIR}/xdg/xfmedia/keybindings.rc

post-install:
	${INSTALL} ${WRKSRC}/src/keybindings.rc \
	    ${DESTDIR}${PREFIX}/share/xfmedia/keybindings.rc

BUILDLINK_DEPMETHOD.libXt=	build

.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
