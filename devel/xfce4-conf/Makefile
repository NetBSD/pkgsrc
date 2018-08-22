# $NetBSD: Makefile,v 1.16 2018/08/22 09:45:01 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.13.4
DISTNAME=	xfconf-${VERSION}
PKGNAME=	xfce4-conf-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://archive.xfce.org/src/xfce/xfconf/4.13/

HOMEPAGE=	http://docs.xfce.org/xfce/xfconf/start
COMMENT=	Xfce client-server configuration storage and query system

PKGCONFIG_OVERRIDE=	xfconf/libxfconf-0.pc.in

CONFIGURE_ARGS+=	--disable-perl-bindings

MAKE_DIRS+=	${PREFIX}/include/xfce4

BUILDLINK_API_DEPENDS.dbus+=		dbus>=1.0.0
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.72

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
