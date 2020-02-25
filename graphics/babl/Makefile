# $NetBSD: Makefile,v 1.32 2020/02/25 14:55:36 brook Exp $

DISTNAME=	babl-0.1.72
CATEGORIES=	graphics
MASTER_SITES=	https://download.gimp.org/pub/babl/0.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c99

MESON_ARGS+=	-Dwith-docs=false
MESON_ARGS+=	-Denable-gir=false

PKGCONFIG_OVERRIDE+=	babl.pc.in

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		Darwin not_Darwin
.if ${OPSYS} == "Darwin"
PLIST.Darwin=		yes
PLIST_SUBST+=  		SOEXT="dylib"
.else
PLIST.not_Darwin=	yes
PLIST_SUBST+=  		SOEXT="so"
.endif

# Apply removals to post-wrapper transformed arguments.
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,babl.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,babl.map

.if ${OPSYS} == "Darwin"
#
# Meson uses .dylib for Darwin shared libraries, but G_MODULE_SUFFIX
# is always .so on Unix, including Darwin.  This is under discussion
# at https://gitlab.gnome.org/GNOME/glib/issues/1413 but for now
# rename the plugins and reset their internal ID to match the new
# name.
#
post-install:
	cd ${DESTDIR}/${PREFIX}/lib/babl-0.1 && for i in *.dylib; do \
		install_name_tool -id ${PREFIX}/lib/babl-0.1/$${i%.dylib}.so $${i}; \
		mv "$${i}" "$${i%.dylib}.so" \
	; done
.endif

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
