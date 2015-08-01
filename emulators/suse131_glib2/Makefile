# $NetBSD: Makefile,v 1.4.4.1 2015/08/01 09:19:55 tron Exp $

PKGNAME=	suse_glib2-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	gio-branding-upstream-2.38.2-8.2.noarch
RPMUPDPKGS+=	glib2-tools-2.38.2-8.2.${SUSE_ARCH}
RPMUPDPKGS+=	libgio-2_0-0-2.38.2-8.2.${SUSE_ARCH}
RPMUPDPKGS+=	libglib-2_0-0-2.38.2-8.2.${SUSE_ARCH}
RPMUPDPKGS+=	libgmodule-2_0-0-2.38.2-8.2.${SUSE_ARCH}
RPMUPDPKGS+=	libgobject-2_0-0-2.38.2-8.2.${SUSE_ARCH}
RPMUPDPKGS+=	libgthread-2_0-0-2.38.2-8.2.${SUSE_ARCH}

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
