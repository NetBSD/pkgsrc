# $NetBSD: Makefile,v 1.85 2012/09/15 10:04:05 obache Exp $

DISTNAME=		atk-2.4.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/atk/2.4/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.gnome.org/atk/
COMMENT=		Set of interfaces for accessibility
LICENSE=		gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	atk.pc.in

# glib-mkenums overflows a 2048kb stack on atkobject.h
UNLIMIT_RESOURCES=	stacksize

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.31.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
