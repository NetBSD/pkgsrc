# $NetBSD: Makefile,v 1.4 2014/09/07 12:26:44 obache Exp $

PKGNAME=	suse_pulseaudio-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	libpulse0-4.0.git.270.g9490a-8.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Pulseaudio

EMUL_MODULES.linux=	base dbus libsndfile libwrap libjson x11

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
