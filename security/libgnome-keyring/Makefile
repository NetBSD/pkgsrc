# $NetBSD: Makefile,v 1.1.1.1 2010/06/01 10:56:27 drochner Exp $
#

DISTNAME=	libgnome-keyring-2.30.1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome-keyring/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME password and secret manager

CONFLICTS+=	gnome-keyring<2.30

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	library/gnome-keyring-1.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/eggdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
