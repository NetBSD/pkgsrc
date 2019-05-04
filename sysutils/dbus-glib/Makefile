# $NetBSD: Makefile,v 1.43 2019/05/04 08:42:24 rillig Exp $

DISTNAME=	dbus-glib-0.110
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-glib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	GLib bindings for the D-BUS message bus system
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		NO

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	dbus-glib-1.pc.in

CONFIGURE_ARGS+=	--disable-ansi
CONFIGURE_ARGS+=	--disable-asserts
CONFIGURE_ARGS+=	--disable-gcov
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--enable-silent-rules
CONFIGURE_ARGS+=	--enable-checks

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.40
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.8
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
