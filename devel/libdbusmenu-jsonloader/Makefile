# $NetBSD: Makefile,v 1.2 2017/05/29 12:20:23 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/libdbusmenu/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-jsonloader-/}
COMMENT=	Test libraries for development with libdbusemenu

CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--disable-dumper
CONFIGURE_ARGS+=	--disable-introspection
CONFIGURE_ARGS+=	--disable-vala
CONFIGURE_ARGS+=	--enable-tests

post-configure:
	${LN} -sf ${BUILDLINK_DIR}/lib/libdbusmenu-glib.la \
		${WRKSRC}/libdbusmenu-glib/

BUILD_DIRS=	tests

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
