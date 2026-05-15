# $NetBSD: Makefile,v 1.47 2026/05/15 17:00:55 wiz Exp $

PKGREVISION= 12
.include "../../meta-pkgs/libdbusmenu/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gtk3-/}
COMMENT=	GTK3+ library created by pulling some code from indicator-applet

TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection

CONFIGURE_ARGS+=	--enable-gtk
CONFIGURE_ARGS+=	--with-gtk=3
CONFIGURE_ARGS+=	--disable-dumper
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		HAVE_VALGRIND_TRUE=
CONFIGURE_ENV+=		HAVE_VALGRIND_FALSE='\#'

post-configure:
	${LN} -sf ${BUILDLINK_DIR}/lib/libdbusmenu-glib.la \
		${WRKSRC}/libdbusmenu-glib/

BUILD_DIRS=	libdbusmenu-gtk

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
