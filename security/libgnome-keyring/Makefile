# $NetBSD: Makefile,v 1.11 2012/09/15 10:06:16 obache Exp $
#

DISTNAME=	libgnome-keyring-3.4.1
PKGREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome-keyring/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME password and secret manager

CONFLICTS+=	gnome-keyring<2.30

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake intltool msgfmt pkg-config xgettext
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	library/gnome-keyring-1.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=    dbus>=1.2.1
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
