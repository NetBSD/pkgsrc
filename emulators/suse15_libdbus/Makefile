# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:18 wiz Exp $

PKGNAME=	suse_libdbus-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	dbus-1-1.12.2-150400.16.52.${SUSE_ARCH}
RPMPKGS+=	libdbus-1-3-1.12.2-150400.16.52.${SUSE_ARCH}
RPMPKGS+=	libaudit1-3.0.6-150400.2.13.${SUSE_ARCH}
RPMPKGS+=	libcap-ng0-0.7.9-4.37.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for DBus

EMUL_MODULES.linux=	base libsystemd

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
