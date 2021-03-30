# $NetBSD: Makefile,v 1.13 2021/03/30 18:09:45 wiz Exp $

PKGNAME=	suse_libdbus-${SUSE_VERSION}
PKGREVISION=	8
CATEGORIES=	emulators
RPMUPDPKGS+=	dbus-1-1.8.16-4.36.2.${SUSE_ARCH}
RPMUPDPKGS+=	libdbus-1-3-1.8.16-4.36.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
