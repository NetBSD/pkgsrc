# $NetBSD: Makefile,v 1.1 2022/10/02 17:17:19 wiz Exp $

PKGNAME=	suse_pulseaudio-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libpulse0-15.0-150400.2.10.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Pulseaudio

EMUL_MODULES.linux=	base dbus x11 libsndfile x11

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
