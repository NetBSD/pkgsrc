# $NetBSD: Makefile,v 1.15 2019/07/21 22:24:38 wiz Exp $

PKGREVISION= 14
.include "../../meta-pkgs/libdbusmenu/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gtk3-/}
COMMENT=	GTK3+ library created by pulling some code from indicator-applet

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

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
