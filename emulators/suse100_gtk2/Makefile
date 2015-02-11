# $NetBSD: Makefile,v 1.11 2015/02/11 09:38:13 obache Exp $

DISTNAME=	suse_gtk2-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
DISTFILES=	atk-1.10.3-2.${SUSE_ARCH}.rpm				\
		glib2-2.8.1-3.${SUSE_ARCH}.rpm				\
		gtk2-2.8.3-4.7.${SUSE_ARCH}.rpm				\
		cairo-1.0.0-7.4.${SUSE_ARCH}.rpm			\
		glitz-0.4.4-4.${SUSE_ARCH}.rpm				\
		pango-1.10.0-3.${SUSE_ARCH}.rpm

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-2.x

EMUL_MODULES.linux=	fontconfig freetype2 jpeg png tiff x11

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/etc/opt/gnome/gtk-2.0/gtk.immodules
CHECK_FILES_SKIP+=	${EMULDIR}/etc/opt/gnome/gtk-2.0/gdk-pixbuf.loaders
CHECK_FILES_SKIP+=	${EMULDIR}/etc/opt/gnome/pango/pango.modules

BINSUFFIX?=	# empty
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
