# $NetBSD: Makefile,v 1.22 2023/11/12 13:21:04 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/libdbusmenu/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-glib-/}
COMMENT=	Glib2 library created by pulling some code from indicator-applet

CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--disable-dumper
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		HAVE_VALGRIND_TRUE=
CONFIGURE_ENV+=		HAVE_VALGRIND_FALSE='\#'

INSTALL_DIRS=	libdbusmenu-glib docs

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
