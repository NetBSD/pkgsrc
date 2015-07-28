# $NetBSD: Makefile,v 1.5 2015/07/28 08:49:14 wiz Exp $

PKGNAME=	suse_libSDL-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libSDL-1_2-0-1.2.15-10.4.1.${SUSE_ARCH}
RPMPKGS+=	libSDL_image-1_2-0-1.2.12-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libSDL_ttf-2_0-0-2.0.11-2.1.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for SDL

EMUL_MODULES.linux=	alsa libesd pulseaudio

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
