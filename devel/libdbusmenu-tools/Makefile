# $NetBSD: Makefile,v 1.10 2018/09/03 10:50:18 wiz Exp $

PKGREVISION= 9
.include "../../meta-pkgs/libdbusmenu/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}
COMMENT=	Tools for development with libdbusemenu

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--enable-dumper
CONFIGURE_ARGS+=	--disable-introspection
CONFIGURE_ARGS+=	--disable-vala
CONFIGURE_ARGS+=	--enable-tests

post-configure:
	${LN} -sf ${BUILDLINK_DIR}/lib/libdbusmenu-glib.la \
		${WRKSRC}/libdbusmenu-glib/

BUILD_DIRS=	tools

REPLACE_PYTHON+=	tools/dbusmenu-bench

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.3
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
