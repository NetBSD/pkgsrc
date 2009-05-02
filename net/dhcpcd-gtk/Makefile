# $NetBSD: Makefile,v 1.6 2009/05/02 22:56:12 abs Exp $
#

DISTNAME=		dhcpcd-ui-0.4.0
PKGNAME=		dhcpcd-gtk-0.4.0
CATEGORIES=		net
LICENSE=		modified-bsd
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		GTK+ systray monitor for dhcpcd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${PREFIX}/share/gnome/autostart

DEPENDS+=		dhcpcd-dbus>=0.4.0:../../net/dhcpcd-dbus

BUILD_DEPENDS+=		librsvg>=0:../../graphics/librsvg

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
