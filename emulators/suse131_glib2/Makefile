# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:17 obache Exp $

DISTNAME=	suse_glib2-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	gio-branding-upstream-2.38.1-1.1.noarch
RPMPKGS+=	glib2-tools-2.38.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libgio-2_0-0-2.38.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libglib-2_0-0-2.38.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libgmodule-2_0-0-2.38.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libgobject-2_0-0-2.38.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libgthread-2_0-0-2.38.1-1.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GLib-2.x

CONFLICTS+=	suse_gtk2<13.1nb1

EMUL_MODULES.linux=	base libffi

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/lib${ABISUFFIX}/gio/modules/giomodule.cache
CHECK_FILES_SKIP+=	${EMULDIR}/usr/share/glib-2.0/schemas/gschemas.compiled

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
