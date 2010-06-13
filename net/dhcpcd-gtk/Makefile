# $NetBSD: Makefile,v 1.12 2010/06/13 22:45:09 wiz Exp $
#

DISTNAME=		dhcpcd-ui-0.5.0
PKGNAME=		dhcpcd-gtk-0.5.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
MASTER_SITES+=		http://roy.aydogan.net/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		GTK+ systray monitor for dhcpcd
LICENSE=		modified-bsd

DEPENDS+=		dhcpcd-dbus>=0.5.0:../../net/dhcpcd-dbus

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gtk+

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
