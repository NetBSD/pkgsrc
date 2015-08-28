# $NetBSD: Makefile,v 1.14 2015/08/28 13:24:38 wiz Exp $

DISTNAME=	libgnome-keyring-3.12.0
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome-keyring/3.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME password and secret manager

CONFLICTS+=	gnome-keyring<2.30

USE_TOOLS+=		gmake intltool msgfmt pkg-config xgettext
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	library/gnome-keyring-1.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=    dbus>=1.2.1
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
