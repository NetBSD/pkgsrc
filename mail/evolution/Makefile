# $NetBSD: Makefile,v 1.284 2025/01/30 11:29:20 wiz Exp $

DISTNAME=	evolution-3.44.4
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Evolution/
COMMENT=	Mail and calendar client from GNOME
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config itstool
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
USE_TOOLS+=	gdbus-codegen

DEPENDS+=	highlight-[0-9]*:../../textproc/highlight

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/evolution

CMAKE_CONFIGURE_ARGS+=	-DMAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GNOME_DESKTOP=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_CONTACT_MAPS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_AUTOAR=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_WEATHER=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PST_IMPORT=OFF

PKGCONFIG_OVERRIDE+=	evolution-calendar.pc.in
PKGCONFIG_OVERRIDE+=	evolution-mail.pc.in
PKGCONFIG_OVERRIDE+=	evolution-shell.pc.in
PKGCONFIG_OVERRIDE+=	src/libemail-engine/libemail-engine.pc.in

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/cmake/build.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=3.44
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../mail/libytnef/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/cmark/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
