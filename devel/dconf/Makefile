# $NetBSD: Makefile,v 1.43 2018/04/18 08:26:42 wiz Exp $

DISTNAME=	dconf-0.28.0
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

SUBST_CLASSES.Darwin+=	libname
SUBST_STAGE.libname=	pre-configure
SUBST_FILES.libname=	client/Makefile.in
SUBST_FILES.libname+=	gsettings/Makefile.in
SUBST_SED.libname=	-e "s|-Wl,-soname=|-install_name ${PREFIX}/lib/|g"
SUBST_SED.libname+=	-e "/^libdconfsettings_so_LDFLAGS/s,$$, -install_name ${PREFIX}/lib/gio/modules/libdconfsettings.so,g"

BUILDLINK_DEPMETHOD.vala=	build
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
#.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
.include "../../devel/py-meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
