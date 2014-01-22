# $NetBSD: Makefile,v 1.2 2014/01/22 12:22:36 obache Exp $

DISTNAME=	suse_libdbus-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	dbus-1-1.7.4-4.4.1.${SUSE_ARCH}
RPMPKGS+=	libdbus-1-3-1.7.4-4.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
