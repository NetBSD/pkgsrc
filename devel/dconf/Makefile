# $NetBSD: Makefile,v 1.51 2019/08/16 10:54:51 wiz Exp $

DISTNAME=	dconf-0.32.0
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

# gtk-doc wants to run dconf-scan, but that does not find its library libdconf.so.1
# https://bugzilla.gnome.org/show_bug.cgi?id=795348
#MESON_ARGS+=		-D enable-gtk-doc=true
# man option does not work without gtk-doc option
#MESON_ARGS+=		-D enable-man=true
MESON_ARGS+=		-D bash_completion=false

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
	    ${DESTDIR}${PREFIX}/lib/libdconf.1.dylib
	install_name_tool \
	    -id ${PREFIX}/lib/gio/modules/libdconfsettings.dylib \
	    -change \
	    "@rpath/libdconfsettings.dylib" \
	    "${PREFIX}/gio/modules/libdconfsettings.dylib" \
	    ${DESTDIR}${PREFIX}/lib/gio/modules/libdconfsettings.dylib
	install_name_tool \
	    -id ${PREFIX}/lib/libdconf.dylib \
	    -change \
	    "@rpath/libdconf.1.dylib" \
	    "${PREFIX}/lib/libdconf.1.dylib" \
	    ${DESTDIR}${PREFIX}/bin/dconf
.endif

BUILDLINK_DEPMETHOD.vala=	build
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.44.0
#.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
.include "../../devel/py-meson/build.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
