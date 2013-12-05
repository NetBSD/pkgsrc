# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:16 obache Exp $

DISTNAME=	suse_pulseaudio-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	libpulse0-4.0.git.270.g9490a-4.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Pulseaudio

EMUL_MODULES.linux=	base dbus libsndfile libwrap libjson x11

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
