# $NetBSD: Makefile,v 1.2 2014/03/14 09:26:56 obache Exp $

DISTNAME=	suse_glx-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	Mesa-9.2.3-61.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libEGL1-9.2.3-61.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libGL1-9.2.3-61.9.1.${SUSE_ARCH}
RPMPKGS+=	Mesa-libglapi0-9.2.3-61.9.1.${SUSE_ARCH}
RPMPKGS+=	libgbm1-9.2.3-61.9.1.${SUSE_ARCH}
RPMPKGS+=	libwayland-client0-1.2.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libwayland-server0-1.2.1-1.1.${SUSE_ARCH}
RPMPKGS+=	libudev1-208-6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for OpenGL/Mesa

EMUL_MODULES.linux=	x11 drm

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
