# $NetBSD: Makefile,v 1.2 2013/12/06 10:35:17 obache Exp $

DISTNAME=	suse_pulseaudio-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	libpulse0-4.0.git.270.g9490a-1.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Pulseaudio

EMUL_MODULES.linux=	base dbus libsndfile libwrap libjson x11

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
