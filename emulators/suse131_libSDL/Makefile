# $NetBSD: Makefile,v 1.3 2015/02/11 09:38:17 obache Exp $

DISTNAME=	suse_libSDL-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libSDL-1_2-0-1.2.15-10.1.2.${SUSE_ARCH}
RPMPKGS+=	libSDL_image-1_2-0-1.2.12-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libSDL_ttf-2_0-0-2.0.11-2.1.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for SDL

EMUL_MODULES.linux=	alsa libesd pulseaudio

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
