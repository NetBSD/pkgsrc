# $NetBSD: Makefile,v 1.7 2021/05/20 06:29:56 nia Exp $

DISTNAME=	tracker-3.0.1
PKGNAME=	gnome-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tracker/3.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Tracker
COMMENT=	Desktop-neutral metadata-based search framework
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config xgettext

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # xsltproc

MESON_ARGS+=	-Ddocs=false
MESON_ARGS+=	-Dsystemd_user_services=false

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src:${WRKSRC}/output/src/libtracker-sparql/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PREFER.sqlite3=	pkgsrc # fts5
.endif

SUBST_CLASSES+=		asciidoc
SUBST_STAGE.asciidoc=	pre-configure
SUBST_MESSAGE.asciidoc=	Correcting the path to asciidoc files.
SUBST_FILES.asciidoc+=	docs/manpages/meson.build
SUBST_SED.asciidoc+=	-e "s,/etc/asciidoc,${PREFIX}/share/asciidoc,g"

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/tracker-sparql-3.0.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/tracker-testutils-3.0.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection?=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala?=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>3.28.0
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
