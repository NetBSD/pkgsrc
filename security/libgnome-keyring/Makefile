# $NetBSD: Makefile,v 1.19 2025/04/09 09:35:48 wiz Exp $

DISTNAME=	libgnome-keyring-3.12.0
PKGREVISION=	2
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

CPPFLAGS+=		-DGPGRT_ENABLE_ES_MACROS

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=    dbus>=1.2.1
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
