# $NetBSD: Makefile,v 1.36 2022/06/28 11:33:45 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.16.0
DISTNAME=	xfconf-${VERSION}
PKGNAME=	xfce4-conf-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://archive.xfce.org/src/xfce/xfconf/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/xfce/xfconf/start
COMMENT=	Xfce client-server configuration storage and query system

USE_TOOLS+=	gdbus-codegen

PKGCONFIG_OVERRIDE=	xfconf/libxfconf-0.pc.in

CONFIGURE_ARGS+=	--disable-perl-bindings

MAKE_DIRS+=	${PREFIX}/include/xfce4

CHECK_PORTABILITY_SKIP=	test-driver

BUILDLINK_API_DEPENDS.dbus+=		dbus>=1.0.0
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.72

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
