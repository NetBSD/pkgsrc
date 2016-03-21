# $NetBSD: Makefile,v 1.22 2016/03/21 19:09:09 khorben Exp $

DISTNAME=	libsoup-2.52.2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsoup/2.52/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	HTTP library implementation in C
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		pkg-config gmake intltool msgfmt
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# XXX work around botched gettext check (ignores libintl)
CONFIGURE_ENV+=		DATADIRNAME=share

# XXX: disable Vala bindings otherwise the configure phase fails because is not
# XXX: able to find vapigen.
CONFIGURE_ARGS+=	--enable-vala=no

DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking

PKGCONFIG_OVERRIDE+=	libsoup-2.4.pc.in
PKGCONFIG_OVERRIDE+=	libsoup-gnome-2.4.pc.in

TEST_TARGET=	check

# gcc>=4.2 specific -Werror=XXX flags will be added unconditionally.
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[01].*) || !empty(CC_VERSION:Mgcc-[1-3].*)
CONFIGURE_ARGS+=	--disable-more-warnings
.endif

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=format-nonliteral
CWRAPPERS_APPEND.cc+=	-Wno-error=format-nonliteral
.endif

REPLACE_PYTHON= libsoup/tld-parser.py
PYTHON_FOR_BUILD_ONLY= yes
.include "../../lang/python/application.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
