# $NetBSD: Makefile,v 1.2 2022/10/02 20:57:41 wiz Exp $

PKGNAME=	suse_gtk3-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	gdk-pixbuf-query-loaders-2.42.9-150400.5.6.1.${SUSE_ARCH}
RPMPKGS+=	gtk3-immodule-xim-3.24.34-150400.3.3.1.${SUSE_ARCH}
RPMPKGS+=	gtk3-tools-3.24.34-150400.3.3.1.${SUSE_ARCH}
RPMPKGS+=	libIDL-2-0-0.8.14-150400.13.9.${SUSE_ARCH}
RPMPKGS+=	libatk-1_0-0-2.36.0-150400.2.9.${SUSE_ARCH}
RPMPKGS+=	libatk-bridge-2_0-0-2.38.0-150400.1.9.${SUSE_ARCH}
RPMPKGS+=	libatspi0-2.42.0-150400.2.7.${SUSE_ARCH}
RPMPKGS+=	libcairo-gobject2-1.16.0-150400.9.6.${SUSE_ARCH}
RPMPKGS+=	libcairo2-1.16.0-150400.9.6.${SUSE_ARCH}
RPMPKGS+=	libdatrie1-0.2.9-1.25.${SUSE_ARCH}
RPMPKGS+=	libepoxy0-1.5.9-150400.1.11.${SUSE_ARCH}
RPMPKGS+=	libfribidi0-1.0.10-150400.3.3.1.${SUSE_ARCH}
RPMPKGS+=	libgdk_pixbuf-2_0-0-2.42.9-150400.5.6.1.${SUSE_ARCH}
RPMPKGS+=	libgraphite2-3-1.3.11-2.12.${SUSE_ARCH}
#RPMPKGS+=	libgtk-2_0-0-2.24.33-150400.2.11.${SUSE_ARCH}
RPMPKGS+=	libgtk-3-0-3.24.34-150400.3.3.1.${SUSE_ARCH}
RPMPKGS+=	libharfbuzz0-3.4.0-150400.3.3.1.${SUSE_ARCH}
RPMPKGS+=	libjasper4-2.0.14-150000.3.25.1.${SUSE_ARCH}
RPMPKGS+=	libpango-1_0-0-1.50.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libthai0-0.1.29-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libwayland-cursor0-1.19.0-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libwayland-egl1-99~1.19.0-150400.1.4.${SUSE_ARCH}
RPMPKGS+=	libxkbcommon0-1.3.0-150400.1.13.${SUSE_ARCH}
RPMPKGS+=	orbit2-2.14.19-9.45.${SUSE_ARCH}
RPMPKGS+=	pango-tools-1.50.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	shared-mime-info-2.1-150400.3.5.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-3.x

EMUL_MODULES.linux=	dbus fontconfig freetype2 glib2 glx jpeg xml2 png tiff x11

# These files are managed by the +INSTALL/+DEINSTALL scripts.
#CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gdk-pixbuf-2.0/2.10.0/loaders.cache
CHECK_FILES_SKIP+=	${EMULDIR}/etc/pango/pango${ABISUFFIX}.modules
#CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gio/modules/giomodule.cache
CHECK_FILES_SKIP+=	${EMULDIR}/usr/share/glib-2.0/schemas/gschemas.compiled

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
