# $NetBSD: Makefile,v 1.28 2022/06/30 11:18:15 nia Exp $

PKGREVISION= 26
.include "../../meta-pkgs/libdbusmenu/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}
COMMENT=	Tools for development with libdbusemenu

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--enable-dumper
CONFIGURE_ARGS+=	--disable-introspection
CONFIGURE_ARGS+=	--disable-vala
CONFIGURE_ARGS+=	--enable-tests

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-deprecated-declarations
.endif

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
