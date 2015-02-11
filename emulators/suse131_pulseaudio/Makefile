# $NetBSD: Makefile,v 1.6 2015/02/11 09:38:19 obache Exp $

DISTNAME=	suse_pulseaudio-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libpulse0-4.0.git.270.g9490a-20.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Pulseaudio

EMUL_MODULES.linux=	base dbus libsndfile libwrap libjson x11

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
