# $NetBSD: Makefile,v 1.16 2023/11/14 14:02:17 wiz Exp $

DISTNAME=	fcitx5-5.0.5
PKGREVISION=	10
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5
COMMENT=	Input method framework with extension support
LICENSE=	gnu-lgpl-v2.1

DATAFILES+=	en_dict-20121020.tar.gz
EXTRACT_ONLY=	${DEFAULT_DISTFILES}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}

.for f in ${DATAFILES}
SITES.${f}=	https://download.fcitx-im.org/data/
DISTFILES+=	${f}
.endfor

SUBST_CLASSES+=			fix-machine-id
SUBST_STAGE.fix-machine-id=	pre-configure
SUBST_MESSAGE.fix-machine-id=	Fixing machine-id path
SUBST_FILES.fix-machine-id+=	src/lib/fcitx/misc_p.h
SUBST_SED.fix-machine-id+=	-e 's,/var/lib/dbus/machine-id,${VARBASE}/lib/dbus/machine-id,g'

CONFLICTS+=	fcitx-[0-9]*

USE_CMAKE=		yes
USE_TOOLS+=		bash:run pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
BUILD_DEFS+=		VARBASE

REPLACE_BASH+=		data/fcitx5-diagnose.sh

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

CMAKE_ARGS+=		-DENABLE_WAYLAND=off # cairo-egl is required.
CMAKE_ARGS+=		-DUSE_SYSTEMD=off
CMAKE_ARGS+=		-DLibIntl_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext}/include
CMAKE_ARGS+=		-DLIBUUID_INCLUDE_DIR=${BUILDLINK_PREFIX.libuuid}/include

CXXFLAGS.NetBSD+=	-DLIBKVM_FOUND

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

PKGCONFIG_OVERRIDE+=	src/lib/fcitx-config/Fcitx5Config.pc.in
PKGCONFIG_OVERRIDE+=	src/lib/fcitx-utils/Fcitx5Utils.pc.in
PKGCONFIG_OVERRIDE+=	src/lib/fcitx/Fcitx5Core.pc.in
PKGCONFIG_OVERRIDE+=	src/modules/Fcitx5Module.pc.in

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Fix desktop autostart file installation
SUBST_FILES.xdg=	data/CMakeLists.txt
SUBST_SED.xdg=		-e 's,{CMAKE_INSTALL_FULL_SYSCONFDIR}/xdg/autostart,{CMAKE_INSTALL_PREFIX}/share/examples/fcitx5,'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/fcitx5/org.fcitx.Fcitx5.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/org.fcitx.Fcitx5.desktop

pre-configure:
	${LN} -s ${DISTDIR}/en_dict-20121020.tar.gz \
		${WRKSRC}/src/modules/spell/dict

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/cldr-emoji-annotation/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xcb-imdkit/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
