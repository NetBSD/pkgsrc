# $NetBSD: Makefile,v 1.175 2010/06/03 01:00:46 dsainty Exp $

.include "Makefile.common"

CATEGORIES=		devel

COMMENT=		Some useful routines for C programming (glib2)

USE_TOOLS+=		msgfmt perl:run

PKGCONFIG_OVERRIDE=	glib-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-no-export-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gmodule-no-export-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gobject-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gthread-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gio-unix-2.0.pc.in

# need pcre utf8 + unicode-properties
BUILDLINK_API_DEPENDS.pcre+=	pcre>=7.4nb1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
