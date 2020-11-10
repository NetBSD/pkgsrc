# $NetBSD: Makefile,v 1.1 2020/11/10 18:22:23 nia Exp $

DISTNAME=	gnome-control-center-3.38.1
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
CATEGORIES=	sysutils gnome
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-control-center
COMMENT=	Interface to configure various aspects of the GNOME desktop
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

USE_TOOLS+=	pkg-config msgfmt xgettext

MESON_ARGS+=	-Dcheese=false
MESON_ARGS+=	-Dtests=false
MESON_ARGS+=	-Dwayland=false

.include "../../mk/bsd.prefs.mk"

# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/panels/keyboard/gnome-keybindings.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../audio/gsound/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/libhandy1/buildlink3.mk"
.include "../../graphics/colord/buildlink3.mk"
.include "../../graphics/colord-gtk/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../net/gnome-online-accounts/buildlink3.mk"
.include "../../net/grilo/buildlink3.mk"
.include "../../net/samba4/buildlink3.mk"
.include "../../print/libcups/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/gnome-settings-daemon/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
