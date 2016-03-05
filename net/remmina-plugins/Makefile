# $NetBSD: Makefile,v 1.29 2016/03/05 11:29:11 jperkin Exp $

DISTNAME=	remmina-plugins-0.9.2
PKGREVISION=	24
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=remmina/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://remmina.sourceforge.net/
COMMENT=	Plugins for Remmina, a remote desktop client based on GTK+

DEPENDS+=	rdesktop>=1.6.0:../../net/rdesktop

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool perl pkg-config gmake msgfmt

.include "../../x11/libxkbfile/buildlink3.mk"

# .include "../../chat/libtelepathy/buildlink3.mk" - problematic
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libvncserver=		libvncserver>=0.9.1
.include "../../net/libvncserver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.libgcrypt=		libgcrypt>=1.4.4
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libssh=		libssh>=0.54
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk" # ???
.include "../../x11/vte/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../net/remmina/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
