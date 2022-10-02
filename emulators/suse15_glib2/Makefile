# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_glib2-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	glib2-tools-2.70.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libblkid1-2.37.2-150400.8.3.1.${SUSE_ARCH}
RPMPKGS+=	libgio-2_0-0-2.70.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libglib-2_0-0-2.70.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libgmodule-2_0-0-2.70.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libgobject-2_0-0-2.70.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libgthread-2_0-0-2.70.4-150400.1.5.${SUSE_ARCH}
RPMPKGS+=	libmount1-2.37.2-150400.8.3.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GLib-2.x

EMUL_MODULES.linux=	base libffi libsystemd

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gio/modules/giomodule.cache
CHECK_FILES_SKIP+=	${EMULDIR}/usr/share/glib-2.0/schemas/gschemas.compiled

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
