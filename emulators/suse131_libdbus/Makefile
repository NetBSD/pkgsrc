# $NetBSD: Makefile,v 1.9 2015/01/23 10:34:08 obache Exp $

PKGNAME=	suse_libdbus-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
RPMUPDPKGS+=	dbus-1-1.8.14-4.32.3.${SUSE_ARCH}
RPMUPDPKGS+=	libdbus-1-3-1.8.14-4.32.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
