# $NetBSD: Makefile,v 1.10 2009/09/05 21:43:45 roy Exp $
#

DISTNAME=		dhcpcd-ui-0.4.2
PKGNAME=		dhcpcd-gtk-0.4.2
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		GTK+ systray monitor for dhcpcd
LICENSE=		modified-bsd

DEPENDS+=		dhcpcd-dbus>=0.4.0:../../net/dhcpcd-dbus

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${PREFIX}/share/gnome/autostart

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
