# $NetBSD: Makefile,v 1.6 2014/11/03 09:11:22 obache Exp $

PKGNAME=	suse_libdbus-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	dbus-1-1.8.8-4.20.2.${SUSE_ARCH}
RPMUPDPKGS+=	libdbus-1-3-1.8.8-4.20.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
