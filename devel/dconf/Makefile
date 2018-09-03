# $NetBSD: Makefile,v 1.45 2018/09/03 10:50:17 wiz Exp $

DISTNAME=	dconf-0.28.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/dconf
COMMENT=	Backend for gsettings
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config gmake

REPLACE_PYTHON+=	*.py

SUBST_CLASSES+=		sysdir
SUBST_MESSAGE.sysdir=	Fixes hard-coded dconf database directory name
SUBST_STAGE.sysdir=	post-configure
SUBST_FILES.sysdir+=	engine/dconf-engine-source-system.c
SUBST_FILES.sysdir+=	engine/dconf-engine-profile.c
SUBST_FILES.sysdir+=	tests/engine.c
SUBST_FILES.sysdir+=	bin/dconf-update.vala
SUBST_SED.sysdir=	-e s,/etc,${PKG_SYSCONFDIR},g

# gtk-doc wants to run dconf-scan, but that does not find its library libdconf.so.1
# https://bugzilla.gnome.org/show_bug.cgi?id=795348
#MESON_ARGS+=		-D enable-gtk-doc=true
# man option does not work without gtk-doc option
#MESON_ARGS+=		-D enable-man=true

PKGCONFIG_OVERRIDE=		output/meson-private/dconf.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../mk/bsd.prefs.mk"

post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool \
	    -id ${PREFIX}/lib/libdconf.dylib \
	    -change \
	    "@rpath/libdconf.1.dylib" \
	    "${PREFIX}/lib/libdconf.1.dylib" \
	    ${PREFIX}/lib/libdconf.1.dylib
	install_name_tool \
	    -id ${PREFIX}/lib/gio/modules/libdconfsettings.dylib \
	    -change \
	    "@rpath/libdconfsettings.dylib" \
	    "${PREFIX}/gio/modules/libdconfsettings.dylib" \
	    ${PREFIX}/lib/gio/modules/libdconfsettings.dylib
.endif

BUILDLINK_DEPMETHOD.vala=	build
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
#.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
.include "../../devel/py-meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
