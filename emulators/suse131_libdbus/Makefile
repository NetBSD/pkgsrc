# $NetBSD: Makefile,v 1.8 2014/12/04 12:18:31 obache Exp $

PKGNAME=	suse_libdbus-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
RPMUPDPKGS+=	dbus-1-1.8.12-4.28.2.${SUSE_ARCH}
RPMUPDPKGS+=	libdbus-1-3-1.8.12-4.28.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
