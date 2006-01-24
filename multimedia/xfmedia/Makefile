# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:28 wiz Exp $
#

DISTNAME=		xfmedia-0.9.1
PKGREVISION=		2
CATEGORIES=		multimedia
MASTER_SITES=		http://spuriousinterrupt.org/projects/xfmedia/files/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://spuriousinterrupt.org/projects/xfmedia/
COMMENT=		Xfce media player based on xine

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=          yes
USE_DIRS+=		xdg-1.2
USE_LIBTOOL=            yes
USE_PKGLOCALEDIR=       yes
USE_TOOLS+=             gmake pkg-config

OWN_DIRS=	${PKG_SYSCONFDIR}/xdg/xfmedia

CONF_FILES=	${PREFIX}/share/xfmedia/keybindings.rc \
		${PKG_SYSCONFDIR}/xdg/xfmedia/keybindings.rc

post-install:
	${INSTALL} ${WRKSRC}/src/keybindings.rc \
	    ${PREFIX}/share/xfmedia/keybindings.rc

.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/libexo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
