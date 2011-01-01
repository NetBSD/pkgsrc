# $NetBSD: Makefile,v 1.3 2011/01/01 03:48:54 obache Exp $

DISTNAME=	suse_gtk2-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
DISTFILES=	cairo-1.8.10-3.1.${SUSE_ARCH}.rpm			\
		dbus-1-1.2.24-1.18.${SUSE_ARCH}.rpm			\
		gconf2-2.28.1-3.4.${SUSE_ARCH}.rpm			\
		glib2-2.24.1-2.5.${SUSE_ARCH}.rpm			\
		glib2-branding-upstream-2.24.1-2.5.${SUSE_ARCH}.rpm	\
		gtk2-2.20.1-2.13.${SUSE_ARCH}.rpm			\
		libatk-1_0-0-1.30.0-1.12.${SUSE_ARCH}.rpm		\
		libgio-2_0-0-2.24.1-2.5.${SUSE_ARCH}.rpm		\
		libglib-2_0-0-2.24.1-2.5.${SUSE_ARCH}.rpm		\
		libgmodule-2_0-0-2.24.1-2.5.${SUSE_ARCH}.rpm		\
		libgobject-2_0-0-2.24.1-2.5.${SUSE_ARCH}.rpm		\
		libgthread-2_0-0-2.24.1-2.5.${SUSE_ARCH}.rpm		\
		libpulse0-0.9.21-9.2.${SUSE_ARCH}.rpm			\
		orbit2-2.14.18-2.8.${SUSE_ARCH}.rpm   			\
		pango-1.28.0-2.7.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-2.x

EMUL_MODULES.linux=	fontconfig freetype2 jpeg png tiff x11

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/etc/gtk-2.0/gtk${ABISUFFIX}.immodules
CHECK_FILES_SKIP+=	${EMULDIR}/etc/gtk-2.0/gdk-pixbuf.loaders
CHECK_FILES_SKIP+=	${EMULDIR}/etc/pango/pango${ABISUFFIX}.modules

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
