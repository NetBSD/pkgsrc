# $NetBSD: Makefile,v 1.8 2009/07/27 06:24:54 roy Exp $
#

DISTNAME=		dhcpcd-ui-0.4.1
PKGNAME=		dhcpcd-gtk-0.4.1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		GTK+ systray monitor for dhcpcd
LICENSE=		modified-bsd

DEPENDS+=		dhcpcd-dbus>=0.4.0:../../net/dhcpcd-dbus
BUILD_DEPENDS+=		librsvg-[0-9]*:../../graphics/librsvg

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${PREFIX}/share/gnome/autostart

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
