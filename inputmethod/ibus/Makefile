# $NetBSD: Makefile,v 1.106 2024/06/15 08:51:03 tsutsui Exp $

.include "Makefile.common"

COMMENT=	Intelligent Input Bus

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
TOOL_DEPENDS+=	cldr-emoji-annotation>=37.0.13.0.0.2:../../textproc/cldr-emoji-annotation
TOOL_DEPENDS+=	unicode-character-database>=15.0.0:../../textproc/unicode-character-database
TOOL_DEPENDS+=	unicode-emoji>=15.0:../../textproc/unicode-emoji

PYTHON_VERSIONS_INCOMPATIBLE=	27

GNU_CONFIGURE=			yes
USE_LIBTOOL=			yes
USE_TOOLS+=			pkg-config intltool msgfmt gmake msgmerge
USE_LANGUAGES=			c c++
USE_PKGLOCALEDIR=		yes

GCONF_SCHEMAS+=		ibus.schemas
PKGCONFIG_OVERRIDE+=	ibus-1.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--enable-dconf
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=	--enable-gtk3
CONFIGURE_ARGS+=	--disable-gtk4
CONFIGURE_ARGS+=	--enable-surrounding-text
CONFIGURE_ARGS+=	--enable-introspection=yes
CONFIGURE_ARGS+=	--disable-systemd-services
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
CONFIGURE_ARGS+=	--with-unicode-emoji-dir=${PREFIX}/share/unicode/emoji
CONFIGURE_ARGS+=	--with-emoji-annotation-dir=${PREFIX}/share/unicode/cldr/common/annotations
CONFIGURE_ARGS+=	--with-ucd-dir=${PREFIX}/share/unicode/ucd

# XXX lack of dbusmenu-glib
CONFIGURE_ARGS+=	--disable-appindicator

SUBST_CLASSES+=		dbus
SUBST_STAGE.dbus=	post-configure
SUBST_FILES.dbus=	src/ibusshare.c
SUBST_SED.dbus=		-e 's,/var/lib/dbus/machine-id,${VARBASE}/lib/dbus/machine-id,g'

BUILD_DEFS+=	PKG_SYSCONFBASE VARBASE
MANCOMPRESSED=	yes

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/ibus
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dconf/db/ibus.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/dconf/profile
CONF_FILES+=		${PREFIX}/share/examples/ibus/dconf/db/ibus.d/00-upstream-settings \
			${PKG_SYSCONFDIR}/dconf/db/ibus.d/00-upstream-settings
CONF_FILES+=		${PREFIX}/share/examples/ibus/dconf/profile/ibus \
			${PKG_SYSCONFDIR}/dconf/profile/ibus

.include "../../mk/compiler.mk"
.if ${CC_VERSION:Mgcc-4.1.[0-9]*}
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
.endif

# wayland or not
PLIST_VARS+=		wayland
.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
CONFIGURE_ARGS+=	--enable-wayland
PLIST.wayland=		yes
.else
CONFIGURE_ARGS+=	--disable-wayland
.endif

# Trigger .vala->.c regeneration of files that contain
# "#if USE_GDK_WAYLAND" preprocessing directives since we
# might be on a platform where gtk3 is not built with Wayland.
pre-build:
	${TOUCH} ${WRKSRC}/ui/gtk3/*.vala

.include "../../devel/glib2/schemas.mk"
.include "../../devel/dconf/database.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.6
BUILDLINK_DEPMETHOD.gobject-introspection+=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.46.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
GTK2_IMMODULES=	yes
.include "../../x11/gtk2/modules.mk"
.include "../../x11/gtk2/buildlink3.mk"
GTK3_IMMODULES=	yes
BUILDLINK_API_DEPENDS.gtk3+=		gtk3+>=3.12.0
.include "../../x11/gtk3/modules.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
