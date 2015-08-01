# $NetBSD: Makefile,v 1.10.2.1 2015/08/01 09:19:55 tron Exp $

PKGNAME=	suse_gtk2-${SUSE_VERSION}
PKGREVISION=	7
CATEGORIES=	emulators
RPMUPDPKGS+=	gdk-pixbuf-query-loaders-2.30.1-20.1.${SUSE_ARCH}
RPMUPDPKGS+=	gtk2-tools-2.24.23-7.1.${SUSE_ARCH}
RPMPKGS+=	libIDL-2-0-0.8.14-18.1.3.${SUSE_ARCH}
RPMPKGS+=	libatk-1_0-0-2.10.0-1.1.${SUSE_ARCH}
RPMUPDPKGS+=	libcairo2-1.12.16-3.4.1.${SUSE_ARCH}
RPMUPDPKGS+=	libgdk_pixbuf-2_0-0-2.30.1-20.1.${SUSE_ARCH}
RPMPKGS+=	libgraphite2-3-1.2.0-6.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libgtk-2_0-0-2.24.23-7.1.${SUSE_ARCH}
RPMPKGS+=	libharfbuzz0-0.9.21-1.3.${SUSE_ARCH}
RPMUPDPKGS+=	libjasper1-1.900.1-160.13.1.${SUSE_ARCH}
RPMUPDPKGS+=	libpango-1_0-0-1.36.1-4.2.${SUSE_ARCH}
RPMPKGS+=	libpangox-1_0-0-0.0.2-4.1.3.${SUSE_ARCH}
RPMPKGS+=	orbit2-2.14.19-15.1.3.${SUSE_ARCH}
RPMUPDPKGS+=	pango-tools-1.36.1-4.2.${SUSE_ARCH}
RPMPKGS+=	shared-mime-info-1.1-2.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-2.x

EMUL_MODULES.linux=	fontconfig freetype2 glib2 glx jpeg xml2 png tiff x11

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gtk-2.0/2.10.0/gtk.immodules
CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gdk-pixbuf-2.0/2.10.0/loaders.cache
CHECK_FILES_SKIP+=	${EMULDIR}/etc/pango/pango${ABISUFFIX}.modules
CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gio/modules/giomodule.cache
CHECK_FILES_SKIP+=	${EMULDIR}/usr/share/glib-2.0/schemas/gschemas.compiled

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
