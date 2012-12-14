# $NetBSD: Makefile,v 1.5 2012/12/14 11:16:48 obache Exp $

DISTNAME=	suse_gtk2-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
RPMPKGS+=	libcairo2-1.10.2-14.1.3.${SUSE_ARCH}
RPMUPDPKGS+=	dbus-1-1.5.8-2.10.1.${SUSE_ARCH}
RPMPKGS+=	dbus-1-glib-0.98-2.1.2.${SUSE_ARCH}
RPMPKGS+=	gconf2-3.2.0-2.2.2.${SUSE_ARCH}
RPMUPDPKGS+=	gdk-pixbuf-query-loaders-2.24.0-2.4.1.${SUSE_ARCH}
RPMPKGS+=	gio-branding-upstream-2.30.1-2.1.2.noarch
RPMPKGS+=	glib2-tools-2.30.1-2.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	gtk2-tools-2.24.7-2.5.1.${SUSE_ARCH}
RPMPKGS+=	pango-tools-1.29.4-2.1.3.${SUSE_ARCH}
RPMPKGS+=	libIDL-2-0-0.8.14-9.1.2.${SUSE_ARCH}
RPMPKGS+=	libatk-1_0-0-2.2.0-2.1.3.${SUSE_ARCH}
RPMPKGS+=	libffi46-4.6.2_20111026-1.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libgdk_pixbuf-2_0-0-2.24.0-2.4.1.${SUSE_ARCH}
RPMPKGS+=	libgio-2_0-0-2.30.1-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libglib-2_0-0-2.30.1-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libgmodule-2_0-0-2.30.1-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libgobject-2_0-0-2.30.1-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libgthread-2_0-0-2.30.1-2.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	libgtk-2_0-0-2.24.7-2.5.1.${SUSE_ARCH}
RPMUPDPKGS+=	libjasper1-1.900.1-149.3.1.${SUSE_ARCH}
RPMPKGS+=	libjson0-0.9-5.1.2.${SUSE_ARCH}
RPMPKGS+=	libpulse0-1.1-1.2.${SUSE_ARCH}
RPMPKGS+=	orbit2-2.14.19-5.1.3.${SUSE_ARCH} 
RPMPKGS+=	shared-mime-info-0.91-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libpango-1_0-0-1.29.4-2.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-2.x

EMUL_MODULES.linux=	fontconfig freetype2 jpeg png tiff x11

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/etc/gtk-2.0/gtk${ABISUFFIX}.immodules
CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gdk-pixbuf-2.0/2.10.0/loaders.cache
CHECK_FILES_SKIP+=	${EMULDIR}/etc/pango/pango${ABISUFFIX}.modules

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
