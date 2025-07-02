# $NetBSD: Makefile,v 1.1 2025/07/02 21:26:09 wiz Exp $

PKGNAME=	suse_gtk4-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	gtk4-tools-4.6.0-150400.3.3.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-4.x

EMUL_MODULES.linux=	dbus fontconfig freetype2 glib2 glx jpeg xml2 png tiff x11

# These files are managed by the +INSTALL/+DEINSTALL scripts.
#CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gdk-pixbuf-2.0/2.10.0/loaders.cache
#CHECK_FILES_SKIP+=	${EMULDIR}/etc/pango/pango${ABISUFFIX}.modules
#CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gio/modules/giomodule.cache
#CHECK_FILES_SKIP+=	${EMULDIR}/usr/share/glib-2.0/schemas/gschemas.compiled

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
