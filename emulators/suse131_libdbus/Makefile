# $NetBSD: Makefile,v 1.7 2014/11/20 09:14:58 obache Exp $

PKGNAME=	suse_libdbus-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
RPMUPDPKGS+=	dbus-1-1.8.10-4.24.2.${SUSE_ARCH}
RPMUPDPKGS+=	libdbus-1-3-1.8.10-4.24.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
