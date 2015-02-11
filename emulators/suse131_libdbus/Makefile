# $NetBSD: Makefile,v 1.10 2015/02/11 09:38:17 obache Exp $

DISTNAME=	suse_libdbus-${SUSE_VERSION}
PKGREVISION=	6
CATEGORIES=	emulators
RPMUPDPKGS+=	dbus-1-1.8.14-4.32.3.${SUSE_ARCH}
RPMUPDPKGS+=	libdbus-1-3-1.8.14-4.32.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
