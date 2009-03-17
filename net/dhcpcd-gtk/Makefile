# $NetBSD: Makefile,v 1.3 2009/03/17 12:03:38 roy Exp $
#

DISTNAME=		dhcpcd-gtk-0.3.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		GTK+ systray monitor for dhcpcd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${PREFIX}/share/gnome/autostart

DEPENDS+=		dhcpcd-dbus>=0.3.0:../../net/dhcpcd-dbus

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
