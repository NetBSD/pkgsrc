# $NetBSD: Makefile,v 1.23 2010/02/16 13:23:50 wiz Exp $
#

DISTNAME=	dbus-glib-0.84
CATEGORIES=	sysutils
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-glib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/dbus
COMMENT=	GLib bindings for the D-BUS message bus system
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		NO
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	dbus-glib-1.pc.in

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=		gtkdoc-rebase

CONFIGURE_ARGS+=	--disable-ansi
CONFIGURE_ARGS+=	--disable-asserts
CONFIGURE_ARGS+=	--disable-doxygen-docs
CONFIGURE_ARGS+=	--disable-gcov
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--disable-verbose-mode
CONFIGURE_ARGS+=	--disable-xml-docs
CONFIGURE_ARGS+=	--enable-checks
CONFIGURE_ARGS+=	--with-xml=expat

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.1
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
