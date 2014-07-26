# $NetBSD: Makefile,v 1.3.2.1 2014/07/26 10:08:16 tron Exp $

DISTNAME=	suse_libdbus-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	dbus-1-1.7.4-4.16.2.${SUSE_ARCH}
RPMUPDPKGS+=	libdbus-1-3-1.7.4-4.16.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
