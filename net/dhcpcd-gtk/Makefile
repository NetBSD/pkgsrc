# $NetBSD: Makefile,v 1.11 2010/05/24 21:12:53 roy Exp $
#

DISTNAME=		dhcpcd-ui-0.5.0
PKGNAME=		dhcpcd-gtk-0.5.0
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
