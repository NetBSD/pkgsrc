# $NetBSD: Makefile,v 1.55 2023/11/08 13:20:25 wiz Exp $

DISTNAME=	grilo-plugins-0.3.10
PKGREVISION=	19
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/grilo-plugins/0.3/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Grilo
COMMENT=	Plugins for grilo media browser
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config xgettext itstool
USE_TOOLS+=	gdbus-codegen

LDFLAGS.SunOS+=	-lsocket

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	grilo-plugins-0.3.pc.in

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/lua53/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../net/grilo/buildlink3.mk"
.include "../../net/libgdata/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
