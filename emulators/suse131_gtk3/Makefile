# $NetBSD: Makefile,v 1.1 2021/11/25 15:39:48 ryoon Exp $

PKGNAME=	suse_gtk3-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	gtk3-tools-3.10.4-12.1.${SUSE_ARCH}
RPMUPDPKGS+=	gtk3-immodule-xim-3.10.4-12.1.${SUSE_ARCH}
RPMUPDPKGS+=	libgtk-3-0-3.10.4-12.1.${SUSE_ARCH}
RPMUPDPKGS+=	libcairo-gobject2-1.12.16-3.4.1.${SUSE_ARCH}
RPMUPDPKGS+=	libatk-bridge-2_0-0-2.10.2-12.1.${SUSE_ARCH}
RPMPKGS+=	libxkbcommon0-0.3.0-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libwayland-cursor0-1.2.1-1.1.${SUSE_ARCH}
RPMUPDPKGS+=	libatspi0-2.10.2-12.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-3.x
LICENSE=	gnu-lgpl-v2.1

EMUL_MODULES.linux=	dbus gtk2

ABISUFFIX?=	# empty
BINSUFFIX?=	# empty
FILES_SUBST+=	ABISUFFIX=${ABISUFFIX:Q}
FILES_SUBST+=	BINSUFFIX=${BINSUFFIX:Q}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
