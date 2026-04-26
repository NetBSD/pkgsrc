# $NetBSD: Makefile,v 1.32 2026/04/26 19:48:17 vins Exp $

DISTNAME=	colord-1.4.8
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	https://www.freedesktop.org/software/colord/releases/ \
		http://ftp.slackware.com/pub/slackware/slackware64-current/source/l/colord/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/colord/
COMMENT=	Device color profile management daemon
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config intltool msgfmt
USE_PKGLOCALEDIR=	yes

BUILD_DEFS+=	VARBASE
SHAREDIR=	${PREFIX}/share
EGDIR=		${SHAREDIR}/examples/colord

USE_PKGLOCALEDIR=	yes

COLORD_USER=		colord
COLORD_GROUP=		colord
PKG_GROUPS+=		${COLORD_GROUP}
PKG_USERS+=		${COLORD_USER}:${COLORD_GROUP}
PKG_GECOS.colord=	ColorManager daemon
PKG_SHELL.colord=	${NOLOGIN}
PKG_HOME.colord=	/nonexistent

# required to generate man pages
TOOL_DEPENDS+=		docbook-xsl-ns-[0-9]*:../../textproc/docbook-xsl-ns
DOCBOOK_MANPAGE_XSL=	${SHAREDIR}/xsl/docbook-ns/manpages/docbook.xsl

CONF_FILES+=		share/dbus-1/system.d/org.freedesktop.ColorManager.conf \
			${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.ColorManager.conf

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/colord.pc \
				output/meson-private/colorhug.pc

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	client/cd-util.c examples/cd-libcolord-icc.c \
			man/meson.build lib/colord/cd-icc-store.c \
			src/cd-main.c src/cd-profile.c client/run.sh
SUBST_SED.paths+=	-e "s:/usr/local/share:${SHAREDIR}:g"
SUBST_SED.paths+=	-e "s:/usr/share/color:${SHAREDIR}/color:g"
SUBST_SED.paths+=	-e "s:/var/lib/:@VARBASE/db:g"
SUBST_VARS.paths+=	DOCBOOK_MANPAGE_XSL SH


SUBST_CLASSES+=		target
SUBST_STAGE.target=	pre-build
SUBST_MESSAGE.target=	Replacing meson custom target.
SUBST_FILES.target=	data/cmf/meson.build \
			data/illuminant/meson.build \
			data/profiles/meson.build
SUBST_SED.target+=	-e "s:cd_create_profile:run_cd_create_profile:g"
SUBST_SED.target+=	-e "s:cd_idt8:run_cd_idt8:g"

MESON_ARGS+=		-Dlocalstatedir=${VARBASE} \
			-Ddaemon_user=colord \
			-Dman=true \
			-Dbash_completion=true \
			-Dcompletionsdir=share/bash-completion/completions \
			-Dpnp_ids=${SHAREDIR}/hwdata/pnp.ids \
			-Dargyllcms_sensor=false \
			-Dsystemd=false

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
MESON_ARGS+=	-Dudev_rules=true
.else
MESON_ARGS+=	-Dudev_rules=false
.endif

.include "options.mk"

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libgusb/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../sysutils/hwdata/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
