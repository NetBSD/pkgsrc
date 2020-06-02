# $NetBSD: Makefile,v 1.249 2020/06/02 08:22:47 adam Exp $

DISTNAME=	evolution-3.34.1
PKGREVISION=	5
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Evolution/
COMMENT=	Mail and calendar client from GNOME
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	intltool msgfmt msgmerge xgettext

DEPENDS+=	highlight-[0-9]*:../../textproc/highlight

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/evolution

CMAKE_ARGS+=	-DMAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}

CMAKE_ARGS+=	-DENABLE_GNOME_DESKTOP=OFF
CMAKE_ARGS+=	-DENABLE_CONTACT_MAPS=OFF
CMAKE_ARGS+=	-DENABLE_AUTOAR=OFF
CMAKE_ARGS+=	-DENABLE_WEATHER=OFF
CMAKE_ARGS+=	-DENABLE_PST_IMPORT=OFF

PKGCONFIG_OVERRIDE+=	evolution-calendar.pc.in
PKGCONFIG_OVERRIDE+=	evolution-mail.pc.in
PKGCONFIG_OVERRIDE+=	evolution-shell.pc.in
PKGCONFIG_OVERRIDE+=	src/libemail-engine/libemail-engine.pc.in

# "gettext version 0.18.3+ required, but version '0.16.1' found instead."
_TOOLS_USE_PKGSRC.msgfmt=	yes
_TOOLS_USE_PKGSRC.msgmerge=	yes
_TOOLS_USE_PKGSRC.xgettext=	yes

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../mail/libytnef/buildlink3.mk"
.include "../../security/gcr/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gspell/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
