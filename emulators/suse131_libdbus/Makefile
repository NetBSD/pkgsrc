# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:15 obache Exp $

DISTNAME=	suse_libdbus-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	dbus-1-1.7.4-4.4.1.${SUSE_ARCH}
RPMPKGS+=	libdbus-1-3-1.7.4-4.4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Pulseaudio

EMUL_MODULES.linux=	base

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
