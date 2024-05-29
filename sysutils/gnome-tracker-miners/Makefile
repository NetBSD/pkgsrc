# $NetBSD: Makefile,v 1.41 2024/05/29 16:34:25 adam Exp $

DISTNAME=	tracker-miners-3.0.1
PKGNAME=	gnome-${DISTNAME}
PKGREVISION=	34
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tracker-miners/3.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Tracker
COMMENT=	Desktop-neutral metadata-based search framework
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

TOOL_DEPENDS+=	asciidoc>=10.1.4:../../textproc/asciidoc

USE_TOOLS+=	pkg-config xgettext gdbus-codegen

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/tracker-miners-3.0

MESON_ARGS+=	-Dnetwork_manager=disabled
MESON_ARGS+=	-Dminer_rss=false
MESON_ARGS+=	-Dsystemd_user_services=false

SUBST_CLASSES+=		sha
SUBST_STAGE.sha=	pre-configure
SUBST_MESSAGE.sha=	Fixing the name of the SHA256 tool.
SUBST_FILES.sha+=	src/tracker-extract/calculate-hash.sh
SUBST_SED.sha+=		-e "s,sha256sum,shasum -a 256,g"

SUBST_CLASSES+=		shabuild
SUBST_STAGE.shabuild=	pre-configure
SUBST_MESSAGE.shabuild=	Fixing the name of the SHA256 tool.
SUBST_FILES.shabuild+=	meson.build
SUBST_SED.shabuild+=	-e "s,sha256sum,shasum,g"

.include "../../lang/python/pyversion.mk"

SUBST_CLASSES+=		asciidoc
SUBST_STAGE.asciidoc=	pre-configure
SUBST_MESSAGE.asciidoc=	Correcting the path to asciidoc files.
SUBST_FILES.asciidoc+=	docs/manpages/meson.build
SUBST_SED.asciidoc+=	-e "s,/etc/asciidoc,${PREFIX}/${PYSITELIB}/asciidoc/resources/,g"

CONF_FILES+=	${PREFIX}/share/examples/xdg/autostart/tracker-miner-fs-3.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/tracker-miner-fs-3.desktop

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/gnome-tracker/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
