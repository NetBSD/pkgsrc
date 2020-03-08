# $NetBSD: Makefile,v 1.17 2020/03/08 16:48:07 wiz Exp $

DISTNAME=	libgnome-keyring-3.12.0
PKGREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnome-keyring/3.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	GNOME password and secret manager
LICENSE=	gnu-lgpl-v2

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
